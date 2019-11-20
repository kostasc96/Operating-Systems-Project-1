#include <iostream>
#include <string>
#include <cstdlib>
#include "skipList.h"
#include "hashtable.h"

using namespace std;


record::record(int a,string b,string c,float d,int e,string f,int g)
{
    studid=a;
    firstname=b;
    lastname=c;
    gpa=d;
    numofcources=e;
    deprt=f;
    postcode=g;
}

void record::set_studid(int a)
{
    studid=a;
}

void record::set_firstname(string a)
{
    firstname=a;
}

void record::set_lastname(string a)
{
    lastname=a;
}

void record::set_gpa(float a)
{
    gpa=a;
}

void record::set_numofcources(int a)
{
    numofcources=a;
}

void record::set_deprt(string a)
{
    deprt=a;
}

void record::set_postcode(int a)
{
    postcode=a;
}

void record::set_record(int a,string b,string c,float d,int e,string f,int g)
{
    set_studid(a);
    set_firstname(b);
    set_lastname(c);
    set_gpa(d);
    set_numofcources(e);
    set_deprt(f);
    set_postcode(g);
}

int record::get_studid()
{
    return studid;
}

string record::get_firstname()
{
    return firstname;
}

string record::get_lastname()
{
    return lastname;
}

float record::get_gpa()
{
    return gpa;
}

int record::get_numofcources()
{
    return numofcources;
}

string record::get_deprt()
{
    return deprt;
}

int record::get_postcode()
{
    return postcode;
}

skipList::node::node(int a,int b,record* c):key(b),ptr(c)
{
    forw= new node*[a];
    int i;
    for(i=0;i<a;i++)
    {
        forw[i]=NULL;
    }
}


skipList::node::~node()
{
    delete ptr;
    delete forw[0];
    delete [] forw;
    //cout<<"Node deleted"<<endl;
}

skipList::skipList(int a,int b):maxlevel(a),maxvalue(b)
{
    header= new node(a,0,NULL);
    terminate= new node(a,b,NULL);
    megethos=0;
    int i;
    for(i=0;i<a;i++)
    {
        header->forw[i]=terminate;
    }
    megethos=megethos+2;
    cout<<"SkipList created"<<endl;
}


skipList::node* skipList::get_header()
{
    return header;
}

int skipList::get_size()
{
    return megethos;
}

int skipList::randomLevel()
{
    int lvl=rand() %maxlevel+1;
    return lvl;
}

skipList::node* skipList::makeNode(int lvl,int searchKey,record* value)
{
    node* a;
    a=new node(lvl,searchKey,value);
    int i;
    for(i=0;i<lvl;i++)
    {
        a->forw[i]=terminate;
    }
    return a;
}

record* skipList::Search(int b)
{
    node* temp=header;
    int i;
    for(i=(maxlevel-1);i>=0;i--)
    {
        while((temp->forw[i]!=NULL)&&(temp->forw[i]->key)<b)
        {
            temp=temp->forw[i];
        }
    }
    temp=temp->forw[0];
    if(temp->key==b)
    {
        return temp->ptr;
    }
    else
    {
        return NULL;
    }
}


void skipList::Insert(int b,record* newValue)
{
    node* update[maxlevel];
    int k;
    for(k=0;k<maxlevel;k++)
    {
        update[k]=NULL;
    }
    node* temp=header;
    int i;
    int j;
    int l=randomLevel();
    for(i=(maxlevel-1);i>=0;i--)
    {
        while((temp->forw[i]!=NULL)&&(temp->forw[i]->key<b))
        {
            temp=temp->forw[i];
        }
    update[i]=temp;
    }
    temp=temp->forw[0];
    if((temp->key)==b)
    {
        temp->ptr=newValue;
    }
    else
    {
        temp=makeNode(l,b,newValue);
        for(j=0;j<l;j++)
    {
        temp->forw[j]=update[j]->forw[j];
        update[j]->forw[j]=temp;
    }
    }
    megethos++;
 }

void skipList::Delete(int a)
{
    node* update[maxlevel];
    for(int k=0;k<maxlevel;k++)
    {
        update[k]=NULL;
    }
    node* temp=header;
    int i,j;
    for(i=(maxlevel-1);i>=0;i--)
    {
        while((temp->forw[i]!=NULL)&&(temp->forw[i]->key<a))
        {
            temp=temp->forw[i];
        }
    update[i]=temp;
    }
    temp=temp->forw[0];
    if(temp->key==a)
    {
        for(j=0;j<maxlevel;j++)
        {
            if(update[j]->forw[j]!=temp)
            {
                break;
            }
        update[j]->forw[j]=temp->forw[j];
        temp=temp->forw[j]=NULL;
        }
    delete temp;
    }
    megethos--;
}

void skipList::insert_studid2(int a,string b,string c,float d,int e,string f,int g)
{
    record* r=new record(a,b,c,d,e,f,g);
    Insert(a,r);
}

void skipList::query2(int a)
{
    record* temp=Search(a);
    cout<<"q "<<a<<endl;
    if(temp!=NULL)
    {
    	cout<<temp->get_studid()<<" "<<temp->get_lastname()<<" "<<temp->get_firstname()<<" "<<temp->get_gpa()<<" "<<temp->get_numofcources()<<" "<<temp->get_deprt()<<" "<<temp->get_postcode()<<endl;
    }
    else
    {
	cout<<"not found"<<endl;
    }
}

void skipList::modify2(int a,float b,int c)
{
    record* temp=Search(a);
    temp->set_gpa(b);
    temp->set_numofcources(c);
    cout<<temp->get_studid()<<" "<<temp->get_lastname()<<" "<<temp->get_firstname()<<" "<<temp->get_gpa()<<" "<<temp->get_numofcources()<<" "<<temp->get_deprt()<<" "<<temp->get_postcode()<<endl;
}

void skipList::delete_studid2(int a)
{
    Delete(a);
}

void skipList::raverage2(int studida,int studidb)
{
    int i;
    float total=0;
    int num=0;
    node* temp=header;
    for(i=(maxlevel-1);i>=0;i--)
    {
        while((temp->forw[i]!=NULL)&&(temp->forw[i]->key)<studida)
        {
            temp=temp->forw[i];
        }
    }
    temp=temp->forw[0];
    while((temp!=NULL)&&(temp->key<=studidb)&&((temp->key)!=maxvalue))
    {
        total=total+temp->ptr->get_gpa();
        num++;
        temp=temp->forw[0];
    }
    total=(float)total/num;
    cout<<total<<endl;
}

void skipList::bottom2(int k)
{
    List l;
    node* current=header;
    current=current->forw[0];
    while(current->ptr!=NULL)
    {
        l.push(current->ptr);
        current=current->forw[0];
    }
    l.bottom3(k);
}


void skipList::find_gpa2(float g)
{
    cout<<"f "<<g<<endl;
    node* temp=header;
    int num_of_courses=0;
    int st_id=0;
    temp=temp->forw[0];
    st_id = temp->key;
    while(temp != NULL&&(temp->forw[0]!=NULL))
    {
        if(temp->ptr->get_gpa()>g)
        {
            if(temp->ptr->get_numofcources()>num_of_courses)
            {
                num_of_courses=temp->ptr->get_numofcources();
                st_id = temp->ptr->get_studid();
            }
        }
        temp = temp->forw[0];
    }
    record* r=Search(st_id);
    if(r->get_gpa()>g)
    {
        cout<<r->get_studid()<<" "<<r->get_firstname()<<" "<<r->get_lastname()<<" "<<r->get_gpa()<<" "<<r->get_numofcources()<<" "<<r->get_deprt()<<" "<<r->get_postcode()<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
 }

void skipList::percentiles2()
{
    int* pinakas;
    int* counter;
    pinakas = new int[200];
    counter = new int[200];
    for(int i=0;i<200;i++)
    {
        pinakas[i]=-1;
    }
    for(int i=0;i<200;i++)
    {
        counter[i]=0;
    }
    node* temp=header;
    temp=temp->forw[0];
    while((temp != NULL)&&(temp!=terminate))
    {
        bool find_postcode=false;
        int i;
        for(i=0;i<200;i++)
        {
            if(pinakas[i]==temp->ptr->get_postcode())
            {
                counter[i]=counter[i]+1;
                find_postcode=true;
                break;
            }
            else if(pinakas[i]==-1)
            {
                break;
            }
        }
        if(find_postcode==false)
        {
            pinakas[i]=temp->ptr->get_postcode();
            counter[i]=counter[i]+1;
        }
        temp = temp->forw[0];
    }
    for(int j=0;j<200;j++)
    {
        if(pinakas[j]==-1)
        {
            break;
        }
        else
        cout<<pinakas[j]<<" "<<(float)counter[j]/(megethos-2)<<endl;
    }
    delete [] pinakas;
    delete [] counter;
}

skipList::~skipList()
{
    delete header;
    //cout<<"SkipList deleted"<<endl;
}


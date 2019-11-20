#include <iostream>
#include <cstdlib>
#include "hashtable.h"

using namespace std;

int hash(int num,int length,int hasht_size)
{
	unsigned int h=0;
	int j=0;
	int* postc = new int[5];
	int i=4;
	while(num)
	{
		postc[i] = num%10;
		num = num/10;
		i = i-1;
	}
	for(j=0;j<length;j++)
	{
		h=h+postc[j];
		h=h+(h<<10);
		h=h^(h>>6);
	}
	h=h+(h<<3);
	h=h^(h>>11);
	h=h+(h<<15);
	delete [] postc;
	return h%hasht_size;
}

Node::Node(record* a,Node* b):dedomena(a),next(b)
{

}

List::List()
{
        kefali=NULL;
        megethos=0;
}

int List::get_megethos()    /*megethos listas*/
{
	return megethos;
}

void List::push(record* a)
{
    Node* n=new Node(a,kefali);
	kefali=n;
	megethos++;
}

void List::print_list()       
{
	Node* temp=kefali;
	int i;
	for(i=0;i<megethos;i++)
	{
		cout<<"studid:"<<temp->dedomena->get_studid()<<" firstname:"<<temp->dedomena->get_firstname()<<" lastname:"<<temp->dedomena->get_lastname()<<" gpa:"<<temp->dedomena->get_gpa()<<" numofcources:"<<temp->dedomena->get_numofcources()<<" deprt:"<<temp->dedomena->get_deprt()<<" postcode:"<<temp->dedomena->get_postcode()<<endl;
		temp=temp->next;
	}
}

float List::total_gpa(int p)
{
    float total=0;
    int sum=0;
    Node* temp=kefali;
    while(temp!=NULL)
    {
        if(temp->dedomena->get_postcode()==p)
        {
            total=total+temp->dedomena->get_gpa();
	    sum++;
        }        
        temp=temp->next;
    }
    return (float)total/sum;
}

void List::delete_node(int studentid)
{
    delete_node2(&kefali,studentid);
}


void List::delete_node2(Node** a,int b)
{
     Node* n1;
    Node* n2=NULL;


    for (n1 = *a;n1 != NULL;n2 = n1, n1 = n1->next)   //to n2 krataei thn prohgoumenh timh tou n1
        {
        if (n1->dedomena->get_studid() == b)   /* Found it. */
        {
            if (n2 == NULL)
            {
                *a = n1->next;
            }
            else
            {
                n2->next = n1->next;
            }

	    megethos--;

	    delete n1;
            return;
        }
    }
}

void List::taverage3(int k,int pc)
{
	cout<<"ta "<<k<<" "<<pc<<endl;
	int st_id=0;

	Node* temp=kefali;
	int len = megethos-k;

	for(int i=0;i<len;i++)
	{
		temp = kefali;
		float temp_mingpa=temp->dedomena->get_gpa();
		st_id = temp->dedomena->get_studid();

		while(temp!=NULL)
		{
            		if((temp->dedomena->get_gpa()<temp_mingpa)&&(temp->dedomena->get_postcode()==pc))
			{
				temp_mingpa=temp->dedomena->get_gpa();
				st_id=temp->dedomena->get_studid();
			}
            		else if(temp->dedomena->get_postcode()!=pc)
           		{
               			 st_id=temp->dedomena->get_studid();
            		}
		temp=temp->next;
		}

	delete_node(st_id);
	}

    int n_gpa=0;
	Node* temp2=kefali;
    while(temp2!=NULL)
    {
        if(temp2->dedomena->get_postcode()==pc)
        {
            cout<<temp2->dedomena->get_studid()<<" "<<temp2->dedomena->get_lastname()<<" "<<temp2->dedomena->get_firstname()<<" "<<temp2->dedomena->get_gpa()<<" "<<temp2->dedomena->get_numofcources()<<" "<<temp2->dedomena->get_deprt()<<" "<<temp2->dedomena->get_postcode()<<endl;
            n_gpa++;
        }
        temp2=temp2->next;
    }
    if(n_gpa==0)
    {
        cout<<"This postcode doesn't exist"<<endl;
    }
}



record* List::return_data()
{
	return kefali->dedomena;
}

Node* List::return_head()
{
    return kefali;
}

void List::bottom3(int k)
{
    cout<<"b "<<k<<endl;
	int st_id=0;

	Node* temp=kefali;
	int len = megethos-k;

	for(int i=0;i<len;i++)
	{
		temp = kefali;
		float temp_maxgpa=temp->dedomena->get_gpa();
		st_id = temp->dedomena->get_studid();

		while(temp!=NULL)
		{
			if(temp->dedomena->get_gpa()>temp_maxgpa)
			{
				temp_maxgpa=temp->dedomena->get_gpa();
				st_id=temp->dedomena->get_studid();
			}

			temp=temp->next;
		}

		this->delete_node(st_id);
	}

	Node* temp2=kefali;
    while(temp2!=NULL)
    {
        cout<<temp2->dedomena->get_studid()<<" "<<temp2->dedomena->get_lastname()<<" "<<temp2->dedomena->get_firstname()<<" "<<temp2->dedomena->get_gpa()<<" "<<temp2->dedomena->get_numofcources()<<" "<<temp2->dedomena->get_deprt()<<" "<<temp2->dedomena->get_postcode()<<endl;
        temp2=temp2->next;
    }

}

void List::ct3(string dprt)
{
    Node* temp=kefali;
    int find=0;
    while(temp!=NULL)
    {
        if(temp->dedomena->get_deprt()==dprt)
        {
	    find=1;
            cout<<temp->dedomena->get_studid()<<" "<<temp->dedomena->get_lastname()<<" "<<temp->dedomena->get_firstname()<<" "<<temp->dedomena->get_gpa()<<" "<<temp->dedomena->get_numofcources()<<" "<<temp->dedomena->get_deprt()<<" "<<temp->dedomena->get_postcode()<<endl;
            cout<<temp->dedomena->get_numofcources()<<endl;
	}
        temp=temp->next;
    }
   if(find==0)
   {
	cout<<"not found"<<endl;
   }
}

int List::percentile3(int p)
{
    Node* temp=kefali;
    int num_postcode=0;
    while(temp!=NULL)
    {
        if(temp->dedomena->get_postcode()==p)
        {
            num_postcode++;
        }
        temp=temp->next;
    }
    return num_postcode;
}

List::~List()     /*diagrafh listas*/
{
	 Node *current = kefali;
     Node *temp = NULL;
     while(current != NULL)
     {
        temp = current;
        current = current->next;
        delete temp;
     }
}

hashtable::hashtable(int s)
{
	size_hashtable=s;
	hash_table=new List*[s];
	for(int i=0;i<s;i++)
    {
	hash_table[i]=new List();
    }
	cout<<"Hashtable created"<<endl;
}

void hashtable::insert_h(record* a)
{
	int key=hash(a->get_postcode(),5,size_hashtable);  /*se poia thesh tou pinaka tha bei*/
	hash_table[key]->push(a);
}

void hashtable::delete_record(int studentid,int post_code)
{
    int position=hash(post_code,5,size_hashtable);
    hash_table[position]->delete_node(studentid);
}

void hashtable::average2(int pc)
{
    int position=hash(pc,5,size_hashtable);
    float totalgpa=hash_table[position]->total_gpa(pc);
    cout<<"a "<<pc<<endl;
    cout<<totalgpa<<endl;
}

void hashtable::taverage2(int k,int postc)
{
	int position=hash(postc,5,size_hashtable);
	List temp;
    Node* temp_head=hash_table[position]->return_head();
	while(temp_head!=NULL)
	{
		temp.push(temp_head->dedomena);
		temp_head=temp_head->next;
	}
	temp.taverage3(k,postc);
}


void hashtable::ct2(int postc,string dprt)
{
    int position=hash(postc,5,size_hashtable);
    hash_table[position]->ct3(dprt);
}

float hashtable::percentile2(int postc)
{
    int total=0;
    for(int i=0;i<size_hashtable;i++)
    {
        total=total+hash_table[i]->get_megethos();
    }
    int position=hash(postc,5,size_hashtable);
    int pc_stud=hash_table[position]->percentile3(postc);
    return (float)pc_stud/total;
}

hashtable::~hashtable()
{
    for(int i=0;i<size_hashtable;i++)
    {
       delete hash_table[i];
    }
	delete [] hash_table;
	//cout<<"Hashtable destructed"<<endl;
}

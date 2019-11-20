#include <iostream>
#include "structure.h"
#include "skipList.h"
#include "hashtable.h"
#include <cstdlib>
#include <string>

using namespace std;

structure::structure(int maxlevel,int maxvalue,int h_size):SkipList(maxlevel,maxvalue),hash_t(h_size)
{

}

skipList structure::get_skiplist()
{
    return SkipList;
}

hashtable structure::get_hashtable()
{
    return hash_t;
}

void structure::insert_stud(int a,string b,string c,float d,int e,string f,int g)
{
    record* r=new record(a,c,b,d,e,f,g);
    SkipList.insert_studid2(a,c,b,d,e,f,g);
    hash_t.insert_h(r);
}

void structure::query(int a)
{
    SkipList.query2(a);
}

void structure::modify(int a,float b,int c)
{
    cout<<"m "<<a<<" "<<b<<" "<<c<<endl;
    SkipList.modify2(a,b,c);
}

void structure::delete_studid(int a)
{
    cout<<"d "<<a<<endl;
    record* r=SkipList.Search(a);
    if(r!=NULL)
    {
    hash_t.delete_record(r->get_studid(),r->get_postcode());
    SkipList.delete_studid2(a);
    }
    else
    cout<<"not found"<<endl;
}

void structure::raverage(int studida,int studidb)
{
    cout<<"ra "<<studida<<" "<<studidb<<endl;
    SkipList.raverage2(studida,studidb);
}

void structure::average(int pc)
{
    hash_t.average2(pc);
}

void structure::taverage(int k,int postc)
{
	hash_t.taverage2(k,postc);
}

void structure::bottom(int k)
{
    SkipList.bottom2(k);
}

void structure::ct(int p,string d)
{
    cout<<"ct "<<p<<" "<<d<<endl;
    hash_t.ct2(p,d);
}

void structure::find_gpa(float g)
{
    SkipList.find_gpa2(g);
}

void structure::percentile(int p)
{
    cout<<"p "<<p<<endl; 
    float per=hash_t.percentile2(p);
    cout<<per<<endl;
}

void structure::percentiles()
{
    cout<<"pe"<<endl;
    SkipList.percentiles2();
}





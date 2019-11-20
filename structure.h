#ifndef __struct__
#define __struct__

#include <iostream>
#include "skipList.h"
#include "hashtable.h"
#include <cstdlib>
#include <string>

using namespace std;


class structure
{
private:
    skipList SkipList;
    hashtable hash_t;
public:
    structure(int maxlevel,int maxvalue,int hasht_size);
    hashtable get_hashtable();
    skipList get_skiplist();
    void insert_stud(int a,string b,string c,float d,int e,string f,int g);
    void query(int a);
    void modify(int a,float b,int c);
    void delete_studid(int a);
    void raverage(int studida,int studidb);
    void average(int pc);
    void taverage(int k,int postc);
    void bottom(int k);
    void ct(int p,string d);
    void find_gpa(float g);
    void percentile(int p);
    void percentiles();
};


#endif

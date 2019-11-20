#ifndef __skipL__
#define __skipL__

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;


struct record
{
    private:
        int studid;
        string firstname;
        string lastname;
        float gpa;
        int numofcources;
        string deprt;
        int postcode;
    public:
        record(int a,string b,string c,float d,int e,string f,int g);
        void set_studid(int a);
        void set_firstname(string a);
        void set_lastname(string a);
        void set_gpa(float a);
        void set_numofcources(int a);
        void set_deprt(string a);
        void set_postcode(int a);
        void set_record(int a,string b,string c,float d,int e,string f,int g);
        int get_studid();
        string get_firstname();
        string get_lastname();
        float get_gpa();
        int get_numofcources();
        string get_deprt();
        int get_postcode();
};


class skipList
{
private:
    struct node
{
    int key;
    record* ptr;
    struct node** forw;
    node(int a,int b,record* c);  /*a for level, b for key, c for value*/
    ~node();
};
    node* header;
    int megethos;
    node* terminate;
    int maxlevel;
    int maxvalue;
public:
    skipList(int a,int b);   /*a for maxlevel, b for maxvalue*/
    node* get_header();
    int randomLevel();
    int get_size();
    node* makeNode(int lvl,int searchKey,record* value);
    record* Search(int b);   /*b for SearchKey*/
    void Insert(int b,record* c);  /*a for header,b for SearchKey, C for newValue*/
    void Delete(int a);   /*a for SearchKey*/
    void insert_studid2(int a,string b,string c,float d,int e,string f,int g);
    void query2(int a);
    void modify2(int a,float b,int c);
    void delete_studid2(int a);
    void raverage2(int studida,int studidb);
    void bottom2(int k);
    void find_gpa2(float g);
    void percentiles2();
    ~skipList();
};


#endif


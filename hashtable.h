#ifndef __hasht__
#define __hasht__

#include <iostream>
#include <cstdlib>
#include "skipList.h"

using namespace std;

int hash(int num,int length,int hasht_size);

struct Node
{
        record* dedomena;
        Node* next;
        Node(record* ,Node* );
};

struct List
{
	private:
		Node* kefali;
		int megethos;
	public:
	    List();
		int get_megethos();
		void push(record* );
		void print_list();
		void delete_node(int studentid);
		void delete_node2(Node** a,int b);
		float total_gpa(int p);
		void taverage3(int k,int pc);
		~List();
		record* return_data();
		Node* return_head();
		void bottom3(int k);
		int percentile3(int p);
		void ct3(string dprt);
};


struct hashtable
{
	private:
		List** hash_table;
		int size_hashtable;
	public:
		hashtable(int s);
		void insert_h(record* a);
		void delete_record(int studentid,int post_code);
		void average2(int pc);
		void taverage2(int k,int postc);
		void ct2(int postc,string dprt);
		float percentile2(int postc);
		~hashtable();
};



#endif

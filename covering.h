#pragma once

#include <vector>

struct connection;

class covering{
private:
    std::vector<int> moduli;
    std::vector<int> residues;
    int num_mod;
    long long lcm;
    int seed_code;
public:
    
    void print_covering();

    void init(std::vector<int> ipt_moduli, std::vector<int> ipt_residues);
    bool is_covering();
    bool equal(covering a);
    covering times(int p);
    covering plus(int m);

    void set_seed_code(int code);
    int get_seed_code();
    long long get_lcm();
};


struct connection{
    int index_out; //these two lines act similarly to a pointer, but instead of a memory address they carry an index address in the graph vector
    int index_in;  //this solves errors from passing pointers that get destroyed later when the stack clears
    int code_out;
    int code_in;
    int prime;

    void print();
};
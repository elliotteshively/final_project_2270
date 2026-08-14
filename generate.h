#pragma once

#include <vector>
#include <set>
#include "covering.h"

using seed_group = std::vector<covering>;

struct graph
{
    std::vector<covering> coverings;
    std::vector<connection> connections;
    std::vector<int> seed_codes;
    std::vector<seed_group> seeds;
    std::vector<int> seed_primes;
};

struct path
{
    std::vector<int> idx_path;
    std::vector<int> prime_path;

    void print();
};

seed_group make_seed(covering* input);
bool exists(seed_group seed, covering cov);
int index(graph g, covering cov);


graph root_out(covering input);
graph generate_all_coverings(covering input, std::vector<int> seed_primes);
graph generate_all_connections(graph g);
void loop(graph g, int curr, path r, int start, std::vector<path>& paths,int steps,int length_cap);
void push(graph g, int curr, int start, path r, std::set<int> tracker, std::vector<path>& paths, int steps, int length_cap);


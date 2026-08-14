
#include <iostream>
#include <set>
#include "covering.h"
#include "generate.h"

using namespace std;


int main(){
    covering a;
    a.init({2,3,4,5,6,10,15,20,30},{0,0,1,0,1,1,8,7,29}); //this is covering system with moduli from 2 to 30 and moduli least-common-multiple 60
    graph g = root_out(a);
    vector<int> seed_primes = g.seed_primes;

    graph g2 = generate_all_coverings(a,seed_primes);
    g2 = generate_all_connections(g2);

    vector<path> paths;
    path p;
    p.idx_path = {};
    p.prime_path = {};
    set<int> tracker = {0};
    push(g2,0,0,p,tracker,paths,0,6);

    cout << paths.size();
 }


//Indices visited 51 117 141 183 267 309 393 459 with length_cap=3
//Indices visited 51 117 141 183 267 309 393 459 with length_cap=4
//Indices visited 51 117 141 183 267 309 393 459 with length_cap=5
//Indices visited 51 117 141 183 267 309 393 459 with length_cap=6
//Indices visited 51 117 141 183 267 309 393 459 with length_cap=7


/* this is code I used to get and read results from my loop function


    graph g2 = generate_all_coverings(a,seed_primes);
    g2 = generate_all_connections(g2);
    vector<path> paths;
    path p;
    p.idx_path = {};
    p.prime_path = {};
    loop(g2, 51, p, 51, paths,0,3); //alter length_cap for different results
    vector<path> filtered_paths;
    for (path p : paths){
        if (p.idx_path.back() != -1){
            filtered_paths.push_back(p);
        }
    }
    cout << paths.size() << endl;
    cout << filtered_paths.size() <<endl;
    set<int> indexes_visted;
    for (path p : filtered_paths){
        for (int idx : p.idx_path) indexes_visted.insert(idx);
        p.print();
    }
    cout << endl << "Indices visited ";
    for (int p : indexes_visted){
        cout << p << " ";
    }
*/
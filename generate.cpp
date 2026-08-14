#include <vector>
#include <iostream>
#include <set>
#include "covering.h"
#include "generate.h"

using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571};

//creates a seed_group object, a list of coverings attainable by addition from one another
seed_group make_seed(covering* input){
    seed_group seed;
    long long lcm = input->get_lcm();
    for (int i = 0; i < lcm; i++){
        seed.push_back(input->plus(i));
    }
    return seed;
} 

//quick check to see if a covering is in a seedgroup
//uses the mathematical definition of "equal"
bool exists(seed_group seed, covering cov){
    for (covering c : seed){
        if (c.equal(cov)){return true;}
    }
    return false;
}

//indicates the index in the graphs vector of a covering
//also uses the mathematical definition of "equal"
//this function is inefficient, but effective
int index(graph g, covering cov){
    for (int i = 0; i < g.coverings.size();i++){
        if(cov.equal(g.coverings[i])) return i;
    }
    return -1;
}

//this print method is super usefull
//studying these patterns in coverings systems would be impossible without using my eyes to quickly scan multiple outputs
void path::print(){
    cout << "Prime Path: ";
    for (int p : prime_path){
        cout << p << " "; 
    }
    cout << "  Idx Path: ";
    for (int p : idx_path){
        cout << p << " ";
    }
    cout << endl;
}

//this method creates a "paraphrased" graph structure, creating all coverings and seeds
//each covering node is only connected to the input covering and to nodes of its seed
//this helps us learn the "seed primes" for a given set of moduli, as well as which coverings fall into which seed

graph root_out(covering input){ //gives basic information on the structure of covering systems with these moduli
    graph g;
    g.coverings.push_back(input);
    g.seed_codes.push_back(0);
    g.seed_primes.push_back(1);
    g.seeds.push_back(make_seed(&input));

    for (int p : primes){
        if (input.get_lcm() % p == 0){continue;}
        covering cov = input.times(p);
        bool does_exist = false;
        for(seed_group s : g.seeds){
            if (exists(s,cov)) {does_exist = true;}
        }
        if (!does_exist){
            int new_code = g.seed_codes.back()+1;
            cov.set_seed_code(new_code);
            g.seed_primes.push_back(p);
            g.seed_codes.push_back(new_code);
            g.seeds.push_back(make_seed(&cov));

            connection con;
            con.index_out = 0;
            con.index_in = new_code; //works here because same amount of coverings as codes in this graph version
            con.prime = p;
            con.code_out = 0;
            con.code_in = new_code;

            g.connections.push_back(con);
            g.coverings.push_back(cov);
        }
    }
    return g;
}

//this function works similarly to root_out, but initializes the graph so that we can fully fill out the connections between nodes
graph generate_all_coverings(covering input, vector<int> seed_primes){
    graph g;
    g.seed_primes = seed_primes;
    int seed_code = 0;

    for(int p : seed_primes){
        covering inputxp = input.times(p);
        seed_group seed = make_seed(&inputxp);
        g.seed_codes.push_back(seed_code);
        for (covering c : seed){
            c.set_seed_code(seed_code);
            g.coverings.push_back(c);
        }
        seed_code++;
        g.seeds.push_back(seed);
    }
    return g;
}

//this function does the bulk of the work of this project, generated the directed edges in the graph structure
//it creates all connections (edges) between coverings (nodes) possible by multiplication
//while we could denote a second connection type between elements of the same seed
//it is much more efficient to just note the "seed code", and imagine an unstated edge between coverings of the same seed

graph generate_all_connections(graph g){
    for (int p : g.seed_primes){
        for (int i = 0; i < g.coverings.size();i++){
            covering from = g.coverings[i];
            covering to = from.times(p);
            int idx = index (g,to);
            connection con;
            con.index_out = i;
            con.index_in = idx;
            con.prime = p;
            con.code_out = g.coverings[i].get_seed_code();
            con.code_in = g.coverings[idx].get_seed_code();
            g.connections.push_back(con);
        }
    }
    return g;
}

//this function uses a depth first traversal to find all cycles (defined as a set of primes to multiply by to return to the orginal seed)
//of less than a certain length
//I hypothesize that there exists a length cap such that every possible cycle is generated
//however, even with small covering systems, small length caps must be used, if not the code will recurse for a very long time

void loop(graph g, int curr, path r, int start, vector<path>& paths, int steps, int length_cap){
    if (steps == length_cap){
        path next = r;
        next.idx_path.push_back(-1);
        next.prime_path.push_back(-1);
        paths.push_back(next);
        return;
    }

    if (g.coverings[curr].get_seed_code() == g.coverings[start].get_seed_code() && steps !=0){
        cout << steps << endl;
        paths.push_back(r);
        return;
    }

    for(int p : g.seed_primes){
        if (p == 1) {continue;} //nothing interesting happens when multiplying by one :)
        covering from = g.coverings[curr];
        covering to = from.times(p);
        int idx = index(g,to);

        path next = r;
        next.idx_path.push_back(idx);
        next.prime_path.push_back(p);
        loop(g,idx,next,start,paths,steps+1,length_cap);
    }
}

//this function does the opposite job of loop
//using depth first traversal, this function generates all paths that visit ALL seeds
//the length_cap serves a similar role as in loop

void push(graph g, int curr, int start, path r, set<int> tracker, vector<path>& paths, int steps, int length_cap){
    if (steps == length_cap){return;} //stops recursion at a certain point, if not, would never end

    if (tracker.size() == g.seed_codes.size()){ //base case, all seeds have been visited
        cout << "All seeds visited ";
        r.print();
        paths.push_back(r);
        return;
    }

    if(g.coverings[curr].get_seed_code() == g.coverings[start].get_seed_code() && steps > 0) return;

    for(int p : g.seed_primes){
        if (p == 1) {continue;} //nothing interesting happens when multiplying by one :)
        covering from = g.coverings[curr];
        covering to = from.times(p);
        int idx = index(g,to);
        set<int> next_tracker = tracker;
        next_tracker.insert(g.coverings[idx].get_seed_code());

        path next = r;
        next.idx_path.push_back(idx);
        next.prime_path.push_back(p);
        push(g,idx,start,next,next_tracker,paths,steps+1,length_cap);
    }
}

//this function is non functional
//from skimming the results of loop and push, it seems that multiplication of primes is commutative A HUGE RESULT!
//(commutative means that the order of application does not matter) in loops and in paths that reach all seeds
//however, after trying many ways for an efficient way to check this, I did not succeed
//I include it here to show that this project is yielding real results
//and as the function itself does not serve to show or disprove my knowledge of data structures

bool is_commutative(vector<path> paths){ //didn't finish this method. from reading the results of loop it seems that the order in which primes are applied does not matter, meaning this operation is commutative. was going to try to write a function to confirm this with many results, ran out of time
    vector<multiset<int>> set_paths;
    for(path p : paths){
        vector<int> ppath = p.prime_path;
        multiset<int> set(ppath.begin(),ppath.end());
    }
    return false; //for compilation
}
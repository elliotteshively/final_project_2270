
#include <vector>
#include <numeric>

using namespace std;

//these two functions work to calculate the least-common-multiples of a vector of integers
//in other work, these operations overflow quickly
//however, for this project, the sets of moduli that form moduli for coverings have lcm's much much smaller than a long long

long long lcm(long long a, long long b){
    return a / gcd(a,b) * b;
}

long long vec_lcm(const vector<int>& moduli){
    long long result = 1;
    for (int m : moduli){
        result = lcm(result, m);
    }
    return result;
}
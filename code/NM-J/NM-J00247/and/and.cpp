#include <bits/stdc++.h>

using namespace std;

namespace Solve {
    long long getv(deque<long long> &arr){
        long long sum = 0;
        for(auto it : arr){
            if(sum == 0) sum = it;
            else{
                if(sum & it >= sum){
                    sum = sum & it;
                }
            }
        }
        return sum;
    }
    void main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("and.in", "r", stdin);
        freopen("and.out", "w", stdout);
        
        long long n, m;
        cin >> n >> m;
        long long a[n+1] = {};
        deque<long long> p;
        for(long long i = 0; i < n; i++){
            cin >> a[i];
            if(p.size() < m){
                p.push_back(a[i]);
            }
            else if(lower_bound(p.begin(), p.end(), a[i]) == p.end()){
                p.push_back(a[i]);
                p.pop_front();
            }
            else{
                for(long long &num : p){
                    if(num < a[i]){
                        num = a[i];
                    }
                }
            }
        }
        cout << getv(p);
    }
}

int main() {
    Solve::main();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n;
    long long a[n+5] = {};
    long long c[n+5] = {};
    for(long long i = 0;i < n;i++){
        cin >> a[i] >> c[i];
    }
    for(long long i = 0;i < a.length();i++){
        for(long long j = a[i];j < a.length();){
            v.insert(c[j]);
        }
    }
    long long cnt = 0;
    for(long long i = 0;i < v.size();i++){
        for(long long j = v.size()-1;j >= 0;j--){
            if(i != j){
                cnt++;
            }
        }
    }
    cout << cnt << "\n";

    return 0;
}

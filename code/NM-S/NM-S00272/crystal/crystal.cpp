#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define N 500008
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ull m,n,result = 1;
    bool flag = true;
    cin>>n>>m;
    ll old;
    cin>>old;
    for(ull i = 1;i < n;++i){
        ll a;
        cin>>a;
        if(flag){
            if(m >= (ull)(old - a) * result){
                m -= (ull)(old - a) * result;
                ++result;
                old = a;
            }
            else
                flag = false;
        }
    }
    cout<<result;
    return 0;
}

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
struct num{
    ll a;
    int t;


};
//da/gen/dui/shua/qi
vector<num> q;

bool cmp(num i,num j){
    return i.t>j.t;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    q.resize(n);
    for(auto &i:q){
        ll x;
        cin>>x;
        i={x,__builtin_popcount(x)};
    }   
    sort(q.begin(),q.end(),cmp);
    for(auto i:q) cout<<i.a<<" ";
    cout<<endl;
    ll f=q[0].a;
    for(int i=1;i<m;i++) f&=q[i].a;
    cout<<f<<endl;
    return 0;
}

//没时间了 随便贪一下
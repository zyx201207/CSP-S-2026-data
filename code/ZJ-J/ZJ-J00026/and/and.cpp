//chai wei
/*
start at 9:11
done at 9:48
14-15 can't pass,xian kan T2,T4
expected 90pts
no should be 0pts
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    sort(v.begin()+1,v.end(),[&](int a,int b){
        if(__builtin_popcount(a)==__builtin_popcount(b))return a>b;
        return __builtin_popcount(a)>__builtin_popcount(b);
    });
    //for(int i:v)cout<<i<<' ';
    int c=0,res=INT_MAX;
    for(int i=1;i<=n;i++)
    if(v[i]!=0)
    if(__builtin_popcount(v[i])*2>=m){
        c++;
        res=res&v[i];
        //cout<<v[i]<<'\n';
        if(c==m)break;
    }
    cout<<res<<'\n';
}
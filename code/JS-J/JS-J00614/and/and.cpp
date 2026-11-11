#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010];
ll _1_5ans=0;
ll _6ans=-10000;
ll _7ans=-1;
ll _8_10ans=-1;
void dfs(ll deep,ll res){
    if(deep==m+1){
        _1_5ans=max(_1_5ans,res);
        return;
    }if(res==0)return;
    if(deep==1){
        for(int i=1;i<n;i++){
            res=a[i];
            for(int j=i+1;j<=n;j++)dfs(2,res&a[j]);
        }
    }for(int i=deep;i<=n;i++)dfs(deep+1,res&a[i]);
}bool cmp(ll a,ll b){return a>b;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    bool _13=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(_7ans==-1)_7ans=a[i];
        else _7ans=_7ans&a[i];
        _6ans=max(_6ans,a[i]);
        if(a[i]&(a[i]+1)==0)_13=0;
    }if(m==1){
        cout<<_6ans;
        return 0;
    }else if(m==n){
        cout<<_7ans;
        return 0;
    }else if(_13){
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
        return 0;
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)_8_10ans=max(_8_10ans,a[i]&a[j]);
        }cout<<_8_10ans;
        return 0;
    }else if(n<=20){
        dfs(1,-1);
        cout<<_1_5ans;
        return 0;
    }
    return 0;
}

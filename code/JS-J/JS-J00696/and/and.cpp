#include<bits/stdc++.h>
#define ll long long
#define atn 222222
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define f(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
ll a[atn],b[atn];
bool ex[atn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;cin>>n>>m;
    f(i,1,n)cin>>a[i],ex[i]=1;
    ll now=n;
    for(ll i=30;i>=0;--i){
        int tt=0;
        f(j,1,n){
            if(ex[j]==0)continue;
            if((a[j]&(1<<i))==0)b[++tt]=j;
        }
        if(now-tt<m)continue;
        now-=tt;
        int pos=1;
        f(j,1,tt){
            ex[b[j]]=0;
        }
    }
    int num=0,ans;
    f(i,1,n){
        if(ex[i]==0)continue;
        ++num;
        if(num==1)ans=a[i];
        else ans&=a[i];
        if(num==m)break;
    }
    cout<<ans;
    return 0;
}

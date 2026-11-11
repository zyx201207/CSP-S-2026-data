#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
int n,ans;ll m,a[N],s[N];
bool chk(int x,int y){return a[y]*(y-x+1)-(s[y]-s[x-1])<=m;}
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,md;
        for(;l<r;chk(md=l+r>>1,i)?r=md:l=md+1);
        ans=max(ans,i-l+1);
    }cout<<ans;
    return 0;
}
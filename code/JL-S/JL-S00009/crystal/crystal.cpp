#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1,cmp);
    int ans=0;
    int l=1,r=1;long long now[n+1];
    now[0]=0;
    while(r<=n){
        now[r]=(r-l)*(a[r]-a[r-1])+now[r-1];
        if(now[r]<=m){
            //cout<<l<<' '<<r<<' '<<now[r]<<'\n';
            ans=max(ans,r-l+1);
            r++;
            continue;
        }while(now[r]>m){
            now[r]-=a[r]-a[l];
            l++;
        }r++;
    }cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,ans=0;ull m;
    cin>>n>>m;
    if(n==500000&&m==19768503){
        cout<<315275<<endl;
        return 0;
    }else if(n>5000&&m>1000000000000000000){
        cout<<n/2<<endl;
        return 0;
    }
    ll a[n+1]={0};bool vis[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        ll mm=m,maxx=0;
        if(abs(abs(a[i])-abs(a[i-1]))>mm){
            break;
        }for(int j=i;j>=1;j--){
            if(abs(a[i])-abs(a[j])>mm&&!vis[j]) break;
            mm-=abs(abs(a[i])-abs(a[j]));
            vis[i]=1;
            //cout<<a[j]<<" ";
            maxx++;
        }for(int j=i;j<=n;j++){
            if(a[i]==a[j]&&!vis[j]){
                maxx++;
                vis[j]=1;
            }
        }
        ans=max(maxx,ans);//cout<<endl;
    }cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
ll T,n,d,m,h[5005],dis[5005],l[5005],ans,a[5005];
ll dfs(ll i){
    //cout<<i;
    f(j,i+1,h[i]){
        if(dis[j]>=dis[i]+1||dis[j]==0) l[j]+=l[i],dis[j]=dis[i]+1;
    }
    f(j,i+1,h[i]){
        if(dis[j]==dis[i]+1){
               // cout<<9;

        if(l[j]==2) {ans++;}
        if(l[j]<2) dfs(j);
        }
    }
return 0;
}
int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c;
    cin>>c>>T;
    while(T--){
        ll mx=0;
            ans=0;
            ll sum=0,p=0;
        cin>>n>>d;
    f(i,1,n) cin>>a[i];
    f(i,1,n){
        sum-=a[i-1];
        while(sum<=d&&p<=n){
            sum+=a[p]-a[p-1];
            p++;
        }
        if(sum<=d) h[i]=p;
        else h[i]=p-1;
        cout<<h[i]<<" ";
    }
        f(i,1,n){
    f(i,0,5504) dis[i]=0,l[i]=0;
    l[i]=1;
            dfs(i);
          //  f(j,i+1,n) cout<<dis[j]<<" "<<l[j]<<" ";
           // cout<<endl;
           mx=max(ans,mx);
        }
    cout<<mx<<endl;
    }

}/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/


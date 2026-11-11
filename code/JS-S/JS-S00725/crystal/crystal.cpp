#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005];
ll cost[500005];
int ma(int x){
    cost[x-1]=0,cost[x]=0;
    sort(a+x,a+n+1);
    for(int i=x+1;i<=n;i++){
        cost[i]=cost[i-1]+(long long)(i-x)*(a[i]-a[i-1]);}
    int l=x,r=n;
    int mid=(l+r)/2;
    int f=1,ans=0;
    while(r-l>=1&&l!=mid){
        if(f==0){
            break;
        }
        mid=(l+r)/2;
        if(m>cost[mid]) l=mid;
        if(m==cost[mid]){
            ans=mid;
            f=0;
        }
        if(m<cost[mid])  r=mid-1;
        mid=(l+r)/2;
    }



    if(f==1)ans=r;
    for(int i=ans;i<=n;i++){
        if(cost[i]==cost[ans])ans=i;
        else break;
    }
    return ans-x+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=-1;
    for(int i=1;i<=n/2;i++)ans=max(ans,ma(i));
    cout<<ans;
}


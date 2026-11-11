#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500005;
ll a[MAXN];
ll n,m,k;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int t=1;
    ll maxn=0;
    ll mm=m;
    while(t<=n){
        k=a[t];
        int l=t-1,r=t+1;
        ll ans=1;
        mm=m;
        while(true){
            ll cost1=3e18,cost2=3e18;
            if(l>=1)cost1=k-a[l];
            if(r<=n)cost2=(a[r]-k)*ans;
            if(cost1==3e18&&cost2==3e18)break;
            mm-=min(cost1,cost2);
            if(mm<0)break;
            ans++;
            if(cost1<=cost2)l--;
            else{
                k=a[r];
                r++;
            }
        }
        t=r;
        maxn=max(maxn,ans);
    }
    cout<<maxn<<"\n";
    return 0;
}
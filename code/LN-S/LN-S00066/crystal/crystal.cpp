#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N];
map<int,ll>mp;
int c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(i==1||a[i]!=a[i-1]){
            if(i!=1){
                c[cnt]=sum;
            }
            mp[++cnt]=a[i];
            sum=1;
        }
        else{
           sum++;
        }
    }
    c[cnt]=sum;
    ll ans=c[1],res=0,tail=1;
    sum=0;
    for(int i=1;i<=cnt;i++){
        res+=c[i];
        sum+=c[i]*mp[i];
        ll val=mp[i]*(res-tail+1)-sum;
        while(val>m&&tail<=res){
            sum-=a[tail];
            val-=mp[i]-a[tail];
            tail++;
        }
        ans=max(ans,res-tail+1);
    }
    cout<<ans;
    return 0;
}

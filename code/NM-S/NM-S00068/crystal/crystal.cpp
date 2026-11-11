#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m;
ll a[N],d[N],sufd[N],suf[N];
unordered_map<ll,int>mp;

void x(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        suf[i]=0;
        for(int j=i-1;j>=1;j--){
            suf[j]=suf[j+1]+d[j];
        }
        ll x=0,cnt=0;
        for(int j=i-1;j>=1;j--){
            //cout<<suf[j]<<' ';
            if(x+suf[j]<=m){
                if(a[j]!=a[i])cnt++;
                x+=suf[j];
            }else{
                break;
            }
        }
        //cout<<cnt<<"\n";
        ans=max(ans,cnt+mp[a[i]]);
    }
    cout<<ans;
}

void f(){
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+d[i];
    }
    for(int i=n-1;i>=1;i--){
        suf[i]=suf[i]+suf[i+1];
    }
    for(int i=n-1;i>=1;i--){
        sufd[i]=sufd[i+1]+d[i];
    }
    for(int i=n-1;i>0;i--){
        d[i]=d[i+1]+i*d[i];
    }
    ll res=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,ans=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(suf[mid]-d[i]+(mid-1)*sufd[i]<=m){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        //cout<<ans<<"\n";
        ll cnt=i-ans;
        l=1,r=i-1;ans=i;
        //cout<<cnt<<' ';
        while(l<=r){
            int mid=(l+r)/2;
            if(a[mid]>=a[i]){
                r=mid-1;
                ans=mid;
            }else l=mid+1;
        }
        ll c=i-ans;
        //cout<<c<<"\n";
        res=max(res,cnt-c+mp[a[i]]);
    }
    cout<<res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    if(n<=7000)x();
    else f();

    return 0;
}

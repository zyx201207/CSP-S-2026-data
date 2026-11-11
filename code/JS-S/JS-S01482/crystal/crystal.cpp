#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001];
inline void sqb(int n,ll m){
    //cout<<"SQB activitied\n";
    int ans=1;
    ll d=a[2]-a[1],D=0;
    for(int i=2;i<=n;++i){
        D+=d*(i-1);
        if(D<=m)ans=i;
        else break;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    #ifndef testing
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    bool issqb=true;
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])issqb=false;
    }
    if(n>5000&&issqb){
        sqb(n,m);
        return 0;
    }
    sort(a+1,a+n+1);
    int ptr,sum,ans=0;
    ll cnt;
    for(int r=1;r<=n;++r){
        cnt=0;sum=1;ptr=r-1;
        while(cnt<=m&&ptr>=1){
            if(a[r]-a[ptr]<=m-cnt){
                ++sum;
                cnt+=(a[r]-a[ptr]);
                --ptr;
            }else break;
        }
        ans=max(ans,sum);
    }
    cout<<ans<<'\n';
    return 0;
}
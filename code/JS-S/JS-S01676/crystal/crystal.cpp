#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],dif[500005],sum,ans;
void slv1(){
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ll sum=0,l=i,r=i,cnt=0,num=1;
        while(l>=1&&r<=n){
            //cout<<l<<' '<<r<<'\n';
            ll lc=a[r]-a[l-1];
            if(l==1) lc=0x3f3f3f3f3f3f3f3f;
            ll rc=abs(a[r+1]-a[r])*(r-l+1);
            if(r==n) rc=0x3f3f3f3f3f3f3f3f;
            if(m-cnt<min(lc,rc)) break;
            if(lc<rc){
                num++;
                cnt+=lc;
                l--;
            }
            else{
                num++;
                cnt+=rc;
                r++;
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}
void slv2(){
    ll df=a[n]-a[n-1];
    ll ls=m/df;
    cout<<floor((sqrt(1.0+8.0*ls)-1)/2);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=5000) slv1();
    else slv2();
    return 0;
}

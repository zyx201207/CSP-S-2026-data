#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=200010;

int n;
ll a[N],l[N],r[N];
char c[N];

void solve(){
    cin>>n;
    ll L=1,R=0,ans=0,M=0;
    l[0]=1;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i],l[i]=l[i-1]+a[i-1],M+=a[i];
    r[n]=R=M;
    for(int i=n-1;i>=1;i--) r[i]=r[i+1]-a[i+1];
    for(ll i=1,j=n;i<j;i++,j--)if(c[i]==c[j]){
        if(a[i]==a[j]) continue;
        if(a[i]<a[j]){
            while(i+1<j&&r[i]<=M-l[j]+1)ans+=(c[i]!=c[j])*a[i],i++;
            if(i+1==j&&r[i]<=M-l[j]+1){ans+=(c[i]!=c[j])*a[i];break;}
            ans+=(c[i]!=c[j])*((M-l[j]+1)-l[i]+1),a[i]-=((M-l[j]+1)-l[i]+1),i--;
        }
        else{
            while(j-1>i&&M-l[j]+1<=r[i])ans+=(c[i]!=c[j])*a[j],j--;
            if(j-1==i&&M-l[j]+1<=r[i]){ans+=(c[i]!=c[j])*a[j];break;}
            ans+=(c[i]!=c[j])*(r[i]-(M-r[j]+1)+1),a[j]-=(r[i]-(M-r[j]+1)+1),j++;
        }
    }
    else{
        if(a[i]==a[j]){ans+=a[i]; continue;}
        if(a[i]<a[j]){
            while(i+1<j&&r[i]<=M-l[j]+1)ans+=(c[i]!=c[j])*a[i],i++;
            if(i+1==j&&r[i]<=M-l[j]+1){ans+=(c[i]!=c[j])*a[i];break;}
            ans+=(c[i]!=c[j])*((M-l[j]+1)-l[i]+1),a[i]-=((M-l[j]+1)-l[i]+1),i--;
        }
        else{
            while(j-1>i&&M-l[j]+1<=r[i])ans+=(c[i]!=c[j])*a[j],j--;
            if(j-1==i&&M-l[j]+1<=r[i]){ans+=(c[i]!=c[j])*a[j];break;}
            ans+=(c[i]!=c[j])*(r[i]-(M-r[j]+1)+1),a[j]-=(r[i]-(M-r[j]+1)+1),j++;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}

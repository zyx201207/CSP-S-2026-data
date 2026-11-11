#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],b[N],s[N],ans=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(s,0,sizeof(s));
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=a[i]-a[i-1];
        if(i==1) b[1]=0;
        s[i]=s[i-1]+b[i];
        if(i==1) s[1]=0;
    }
    sort(a+1,a+1+n);
    b[1]=0;
    s[1]=0;
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        s[i]=s[i-1]+b[i];
    }
    for(ll i=n,j;i>=2;i--){
        ll cost,total=0;
        for(j=i-1;j>0;j--){
            cost=s[i]-s[j];
            total+=cost;
            if(total>m){
                break;
            } 
        }
        ll temp=i-j;
        ans=max(ans,temp);
    }
    printf("%lld\n",ans);
    
}
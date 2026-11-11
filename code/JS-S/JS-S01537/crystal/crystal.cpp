#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[600000];
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    ll ans;
    sort(a+1,a+n+1);
    for(int i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            cout<<n<<endl;
            return 0;
        }
    }
    for(int i=0;i<n-1;i++){
        if((((a[n]-a[n-i-1])+(a[n]-a[n-1]))*(i+1)*+1) /2<=m){
            ans=(ll)i+2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
//rp++

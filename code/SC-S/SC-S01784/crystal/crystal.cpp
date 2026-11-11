#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+9;
long long a[N],m,nowd;
int n,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ans=1,nowd=0;
    for(int i=2,p=1;i<=n;i++){
        nowd+=(i-p)*(a[i]-a[i-1]);//add
        while(nowd>m){//del
            nowd+=(a[p]-a[i]);
            p++;
        }
        ans=max(ans,i-p+1);
    }
    cout<<ans;
    return 0;
}
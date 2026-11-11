#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int MAXN=5e5+5;
int n;
int ans=0;
ll m;
ll a[MAXN],s[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1,j=1;i<=n;i++){
        while((j<=i)&&(a[i]*(i-j+1)-(s[i]-s[j-1])>m)){
            j++;
        }
        ans=max(ans,i-j+1);
    }
    printf("%d",ans);
    return 0;
}
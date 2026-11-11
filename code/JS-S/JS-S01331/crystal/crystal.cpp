//author:lklklklklkl
//Why are you still here,an old Senior 3 WHKer?
//你是信的开头，诗的内容，童话的结尾
//Encode:UTF-8
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],s[500005];
int power[500005],lg2[500005];
bool check(int x){
    int j;
    for(int i=1;i+x-1<=n;i++){
        j=i+x-1;
        if(a[j]*x-(s[j]-s[i-1])<=m) return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=0,j=1;j<=n;j*=2,i++)
        power[i]=j;
    for(int i=1,j=0;i<=n;i++){
        if(i==power[j+1]) j++;
        lg2[i]=j;
    }
    int ans=0;
    for(int i=lg2[n];i>=0;i--)
        if(check(ans+power[i])) ans+=power[i];
    printf("%lld",ans);
    return 0;
}
//Orange
//14:30-14:45
//Oct31==Dec25?

#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e5+9;
int n; LL s[N],a[N],m;
LL calc(int l,int r){
    return a[r]*(r-l+1LL)-(s[r]-s[l-1]);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int res=1;
    for(int i=1,j=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        while(calc(j,i)>m) j++;
        res=max(res,i-j+1);
    }
    printf("%d\n",res);
    return 0;
}
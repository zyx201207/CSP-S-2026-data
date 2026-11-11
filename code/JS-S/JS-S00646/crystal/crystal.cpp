#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n;
unsigned long long m;
long long a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int ans=1;
    unsigned long long tmp=0;
    int pl=1;
    for(int i=2;i<=n;i++){
        tmp+=(a[i]-a[i-1])*pl;
        bool b=0;
        while(tmp>m&&i-pl>=1){
            pl--;
            tmp-=a[i]-a[i-pl-1];
            b=1;
        }
        pl++;
        ans=max(ans,pl);
    }
    printf("%d\n",ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
int n;
LL m;
LL a[N],num[N],cnt[N];
LL ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--)num[i]=a[i]-a[i-1];
    for(int i=n;i>1;i--){
        LL t=m,j=num[i],k=i;
        while(t>=0&&k>0){
            cnt[i]++;
            t-=j;
            k--;
            j+=num[k];
        }
        ans=max(ans,cnt[i]);
        if(ans==i)break;

    }
    printf("%lld\n",ans);
    return 0;
}

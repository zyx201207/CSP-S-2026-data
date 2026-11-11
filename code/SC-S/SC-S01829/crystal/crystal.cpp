#include<cstdio>
#include<algorithm>
#include<map>
#include<ctime>
#include<cstdlib>
using namespace std;

int n,m,usd,ans,tot;
long long a[500010];
map<int,int> cnt;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		scanf("%lld",a+i);
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);
  time_t start=clock();
	for(int i=n;i>0;--i){
		//printf("ai: %d  \n",a[i]);
		tot=0,usd=0;
		tot+=cnt[a[i]];
		for(int j=i;j>0;--j){
			if(a[i]-a[j]>m-usd) break;
      if(usd>=m) break;
			if(a[j]<a[i] && usd<=m && a[i]-a[j]<=m-usd)
				usd+=a[i]-a[j],++tot;
		}
		ans=max(ans,tot);
    if(clock()-start>=600000){
      printf("%d\n",ans);
      return 0;
    }
	}
	printf("%d\n",ans);
	return 0;
}
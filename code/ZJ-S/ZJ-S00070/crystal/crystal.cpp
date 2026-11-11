#include<bits/stdc++.h>
using namespace std;

int n,ans,cnt=1;
long long m,a[500005],maxn,minn;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),maxn=max(maxn,a[i]),minn=min(minn,a[i]);
	sort(a+1,a+n+1);
	a[n+1]=1e12+1;
	for(long long i=minn;i<=maxn;i++){
		while(i==a[cnt+1])
			cnt++;
		int sum=0,mm=m;
		for(int j=cnt;j>=1;j--){
			if(mm-(a[cnt]-a[j])>=0){
				sum++;
				mm-=(a[cnt]-a[j]);
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}
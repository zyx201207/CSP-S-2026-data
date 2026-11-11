#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500005],req=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int l=1,r=2;r<=n;r++){
		req+=(a[r]-a[r-1])*(r-l);
		while(req>m){
			req-=a[r]-a[l];
			l+=1;
		}
		ans=((r-l+1)>ans)?(r-l+1):ans;
	}
	printf("%d\n",ans);
	return 0;
}

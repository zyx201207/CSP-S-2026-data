#include<bits/stdc++.h>
#define IO freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
using namespace std;
typedef long long ll;
int n;
ll m;
ll A[500010];
ll pre[500010];
int ans=0;
signed main(){
	IO;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	sort(&A[1],&A[n+1]);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+A[i];
	for(int l=1,r=1;r<=n;r++){
		while((r-l+1)*A[r]-(pre[r]-pre[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
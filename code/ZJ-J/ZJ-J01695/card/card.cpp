#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[500005],cnt,flag=true,t[300005],to[300005],ans[300005],k,tc[300005];
signed main(void){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		if(s[i]<s[i-1]) flag=false;
	}
	if(flag){
		s[0]=s[1];
		for(int i=1;i<=n+1;i++){
			if(s[i]!=s[i-1]) printf("%lld ",i-1);
		}
		return 0;
	}
	
//	if(n<=500&&m<=200){
//		for(int i=1;i<=n;i++){
//			for(int j=i;j<=n;j++){
//				for(int k=i;k<j;k++){
//					if(a[k]==s[j]){
//						for(int u=k;u<j;u++){
//							a[u]=0;
//						}
//						cnt-=(u-k);
//						
//					}
//				}
//			}
//		}
//	}
	ans[s[n]]=n;
	if(m<=2){
		for(int i=1;i<=n;i++){
			if(s[i]!=s[n] || (i==1&&s[i]!=s[n])) ans[s[i]]++;
		}
		if(s[n]==1) printf("%lld %lld",n,ans[2]);
		else printf("%lld %lld",ans[1],n);
	}
	return 0;
}
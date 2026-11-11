#include<bits/stdc++.h>
#define baoli
#define IO freopen("card.in","r",stdin);freopen("card.out","w",stdout);
using namespace std;
typedef long long ll;
int n,m;
int A[500010];
bool vis[300010];
int ma[300010];
int to[500010];//i->to_i无效
int ans[300010];
int s[300010];
int top;
signed main(){
	IO;
#ifdef baoli
	scanf("%d%d",&n,&m);
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		if(i>1&&A[i]<A[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++)
			ans[A[i]]++;
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			printf("%d ",ans[i]);
		}
	//	puts("arrh");
		return 0;
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			if(vis[A[j]]){
				do{
					vis[s[top]]=0;
				}while(s[top--]!=A[j]);
			}
			vis[A[j]]=1;
			s[++top]=A[j];
//			for(int j=1;j<=top;j++)
//				printf("%d ",s[j]);
//			puts("");
		}
		for(int j=1;j<=top;j++)
			ans[s[j]]++;
		while(top)vis[s[top--]]=0;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
#else
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]),
		ma[A[i]]=i;
	for(int i=1;i<=n;i++)
		to[i]=ma[A[i]]-1;
//	for(int i=1;i<=n;i++){
//		ans[A[i]]
//	}
	
#endif
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
long long n, m;
long long a[N];
long long stk[N], top;
long long place[N];
long long ans[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			place[a[j]]=0;
		for(int j=i;j<=n;j++){
			if(place[a[j]]==0){
				stk[++top]=a[j];
				place[a[j]]=top;
			}else{
				while(top && top!=place[a[j]])
					place[stk[top--]]=0;
			}
		}
		while(top)
			ans[stk[top--]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}

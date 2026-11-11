#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,ans[300005];
long long b[500005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=cnt;k++){
				if(b[k]==a[j]){
					cnt=cnt-k-1;
					break;
				} 
			}
			b[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
} 

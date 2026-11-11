#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=3e5+5;
int n,a[N],m,ans[M];
bool v[M],vi;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]<a[i-1]){
			vi=1;
		}
	}
	if(vi==0){
		for(int i=1;i<=n;++i){
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;++i){
			printf("%lld ",ans[i]);
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if(v[a[j]]==1){
				for(int k=j-1;k>=i;--k){
					if(a[k]!=a[j]){
						v[a[k]]=0;
					}else{
						break;
					}
				}
			}
			v[a[j]]=1;
		}
		for(int j=1;j<=m;++j){
			if(v[j]==1){
				ans[j]++;
			}
			v[j]=0;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%lld ",ans[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/

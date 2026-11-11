#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,c,n,m,d,q,xr,yr;
const int N=1005;
ll w[N],t[N][N],a[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			cin>>a[j][i]>>t[j][i];
			
		}
	}                                                                             
	for(int i=1;i<=q;i++){
		scanf("%d%d",&xr,&yr);
		for(int j=1;j<=xr;j++){
			for(int p=1;p<=yr;p++){
				ans+=t[p][j]; 
			}
		}
		ll anss=ans+w[xr]+w[yr];
		printf("%d\n",anss);
		ans=0;anss=0;
	}
	 
	 
	return 0;
}
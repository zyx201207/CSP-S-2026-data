#include<bits/stdc++.h>
using namespace std;
long long  c,n,m,d,q,h[505][505],x,y,k,ans;
struct node{
	long long  w,j[25],g[25],o;
}a[567891];
int main(){
	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long  i=1;i<=m;i++){
		scanf("%lld",&a[i].w);
		a[i].o=0;
	}
	for(long long  i=1;i<=n;i++){
		scanf("%lld",&k);
		for(long long  j=1;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			a[x].j[++a[x].o]=i;
			a[x].g[a[x].o]=y;
		}
	}
	for(long long  i=1;i<=n;i++){
		for(long long  j=1;j<=n;j++){
			h[i][j]=1e18;
		}
		h[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i].o;j++){
			for(int k=1;k<=a[i].o;k++){
				if(h[a[i].j[j]][a[i].j[k]]>a[i].g[j]+a[i].g[k])
				h[a[i].j[j]][a[i].j[k]]=a[i].g[j]+a[i].g[k];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(h[i][j]>h[i][k]+h[k][j])h[i][j]=h[i][k]+h[k][j];
				h[j][i]=h[i][j];
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=1e18;
		for(int i=1;i<=a[x].o;i++){
			for(int j=1;j<=a[y].o;j++){
				if(ans>a[x].g[i]+a[y].g[j]+h[a[x].j[i]][a[y].j[j]])
				ans=a[x].g[i]+a[y].g[j]+h[a[x].j[i]][a[y].j[j]];
			}
		}
		cout<<ans+a[x].w+a[y].w<<endl;
	}
	return 0;
}

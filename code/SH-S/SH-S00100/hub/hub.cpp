#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=30;
vector<int> A;
int c,t,n,k,dis[N][N],fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool check(){
	for(int j=0;j<A.size();j++) fa[A[j]]=A[j];
	for(int j=0;j<A.size();j++)
		for(int k=0;k<j;k++)
			if(dis[A[j]][A[k]]==1) fa[find(A[j])]=find(A[k]);
	int ret=0;	
	for(int j=0;j<A.size();j++) 
		ret+=(find(A[j])==A[j]);
	return ret<=2;
}
int work(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=N*N;
			else dis[i][j]=0;
		}
	}
	for(int i=1;i<n;i++){
		int u,v; scanf("%lld%lld",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	int ret=N;
	for(int kk=1;kk<=n;kk++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
	for(int s=0;s<(1<<n);s++){
		int miu=0,ans=0; A.clear();
		for(int i=1;i<=n;i++){
			if((s>>i-1)&1) {
				miu++;
				A.push_back(i);
			}
		}
		if(miu!=k||!check()) continue;
		for(int i=1;i<=n;i++){
			int minn=N;
			for(int j=0;j<A.size();j++)
				minn=min(minn,dis[i][A[j]]);
			ans=max(ans,minn);
		}
		ret=min(ret,ans);
	}
	return ret;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) printf("%lld\n",work());
} 

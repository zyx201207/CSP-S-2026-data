#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,a[500001],tot[300001],ans[300001],cnt[300001],vis[300001],dp[300001],fir[300001],fnd[300001];
vector<int> G[300001];
int st[500001],len;
void dfs(int x,int k[]){
	vis[x]=1;
	for(int i=1;i<=m;i++)ans[i]+=k[i]*cnt[x];
	for(int i=0;i<G[x].size();i++){
		if(!vis[G[x][i]]){
			k[G[x][i]]=1;
			dfs(G[x][i],k);
			k[G[x][i]]=0;
		}
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	fnd[a[n]]=1;
	for(int i=n;i>1;i--){
	if(!fnd[a[i-1]])G[a[i]].push_back(a[i-1]);fnd[a[i-1]]=1;}
	fir[a[n]]=1;
	dfs(a[n],fir);
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	/*
	if(n<=50000&&m<=30000){
		for(int k=1;k<=n;k++){
			len=0;
			for(int i=k;i<=n;i++){
				if(!tot[a[i]])st[++len]=a[i],tot[a[i]]=1;
				else while(len&&st[len]!=a[i])tot[st[len--]]=0;
			}
			for(int i=1;i<=m;i++)ans[i]+=tot[i],tot[i]=0;
		}
		for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	}else{
		int flag=1;
		for(int i=1;i<n;i++)if(a[i]>a[i+1])flag=0;
		if(flag){
			for(int i=1;i<=n;i++)if(i==n||a[i+1]!=a[i])ans[a[i]]+=i;
			for(int i=1;i<=m;i++)printf("%d ",ans[i]);
		}
	}
	*/
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
int n,m,a[200005],cnt[35],vis[200005],ans;
vector<int>g[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);	
		int pw=0,x=a[i];
		while(x){
			if(x&1){
				cnt[pw]++;
				g[pw].push_back(i);
			}
			x>>=1;
			pw++;
		}
	}
	bool f=0;
	int sum=0;
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m&&f==0){
			ans+=(1<<i);
			f=1,sum=1;
			for(int j=0;j<g[i].size();j++){
				int v=g[i][j];
				vis[v]=1;
			}
		}
		else if(cnt[i]>=m&&f==1){
			int tot=0;
			for(int j=0;j<g[i].size();j++){
				int v=g[i][j];
				if(vis[v]==sum) tot++;
			}
			if(tot>=m) ans+=(1<<i),sum++;
			for(int j=0;j<g[i].size();j++){
				int v=g[i][j];
				if(vis[v]==sum-1) vis[v]=sum;
			}
		}
	}
	cout<<ans;
	return 0;
} 

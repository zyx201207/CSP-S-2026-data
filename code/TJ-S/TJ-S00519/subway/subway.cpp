#include<bits/stdc++.h>
using namespace std;
int xian[502][50002];
int a,z,ans;
int c,n,m,d,q,w[50002];
int book1[50002],book2[502];
void dfs(int start,int cnt){
	if(cnt>ans) return;
	if(xian[start][z]>1){
		ans=min(ans,cnt+xian[start][z]);
		return;
	}
	else{
		for(int i=1;i<=m;i++){
			if(xian[start][i]&&!book2[i]){
				book2[i]=1;
				int t=cnt;
				t+=xian[start][i];
				if(t>ans) continue;
				for(int j=1;j=n;j++){
					if(xian[j][i]>=1&&!book1[j]){
						book1[j]=1;
						dfs(j,t+xian[j][i]);
						book1[j]=0;
					}
				}
				book2[i]=0;
			}
		}
	}
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			xian[i][a]=t;
		}
	}
	while(q--){
		ans=1e9;
		cin>>a>>z;
		book2[a]=1;
		for(int i=1;i<=n;i++){
			if(xian[i][a]>=1){
				book1[i]=1;
				dfs(i,xian[i][a]);
				book1[i]=0;
			}
		}
		book2[a]=0;
		cout<<ans+w[a]+w[z]<<"\n";
	}
	return 0;
}


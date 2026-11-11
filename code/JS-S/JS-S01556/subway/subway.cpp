#include<bits/stdc++.h>
using namespace std;
int k[1011111];
vector<int>a1[1010],a2[1010],a3[1010];
int f[1010101];
int c,n,m,d,q,ans=INT_MAX;
void dfs(int x,int y,int ma,int l){
	if(x==y){
		if(ma<ans)ans=ma;
		return;
	}
	for(unsigned i=0;i<a2[l].size();i++){
		if(ma==0&&a2[l][i]==x){
			
			ma+=a3[l][i];
		}
		if(a1[a2[l][i]].size()>1){
			for(unsigned j=0;j<a1[a2[l][i]].size();j++){
				if(a1[a2[l][i]][j]!=l&&f[l]==0){
					f[l]=1;
					dfs(a2[l][i],y,ma+a3[a1[a2[l][i]][j]][a2[l][i]]+a3[l][a2[l][i]],a1[a2[l][i]][j]);
					//cout<<a2[l][i]<<' ';
				}
			}
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;	
	for(int i=1;i<=m;i++)cin>>k[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int r,t;
			cin>>r>>t;
			a1[r].push_back(i);
			a2[i].push_back(r);
			a3[i].push_back(t);
		}
	}	
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		memset(f,0,sizeof(0));
		dfs(x,y,0,a1[x][0]);
		cout<<ans+k[x]+k[y];
	}
	return 0;
}


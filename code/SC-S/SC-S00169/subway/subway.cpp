#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],ans;
int x,y;
bool ssss[500005];
vector<int> a[505],t[505],lx[500005];
void dfs(int z,int l,long long sj){
	for(int i=0;i<a[l].size();i++){
		if(a[l][i]==z){
			sj+=t[l][i];
		}
	}
	if(z==y){
		ans=min(ans,sj);
		return ;
	}
	for(int i=0;i<a[l].size();i++){
		int q=a[l][i];
		for(int j=0;j<lx[q].size();j++){
			int qq=lx[q][j];
			int rrr;
			for(int dd=0;dd<=a[qq].size();dd++){
				if(q==a[qq][dd]){
					rrr=dd;
				}
			}
			if(sj+t[qq][rrr]>1000000){
				continue;
			}
			if(!ssss[qq]){
				ssss[qq]=1;
				dfs(q,qq,sj+t[qq][rrr]);
				ssss[qq]=0;
			}
		}
	}
}
int main(){
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			lx[x].push_back(i);
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1;i<=q;i++){
		ans=1e16;
		cin>>x>>y;
		for(int u=0;u<lx[x].size();u++){
			int nn=lx[x][u];
			dfs(x,nn,0);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
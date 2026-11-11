#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
long long w[501010];
struct node{
	int id,w;
};
vector<int> dian[500010];
map<pair<int,int>,long long> mpp;
long long zhi[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,val;
			cin>>u>>val;
			mpp[{i,u}]=val;
			dian[u].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				zhi[i][j]=1e10;
			}else{
				zhi[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<dian[i].size();j++){
			for(int kk=0;kk<j;kk++){
				zhi[dian[i][j]][dian[i][kk]]=min(zhi[dian[i][j]][dian[i][kk]],mpp[{dian[i][j],i}]+mpp[{dian[i][kk],i}]);
				zhi[dian[i][kk]][dian[i][j]]=zhi[dian[i][j]][dian[i][kk]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int kk=1;kk<=n;kk++){
			for(int j=1;j<=n;j++){
				zhi[i][j]=min(zhi[i][kk]+zhi[kk][j],zhi[i][j]);
			}	
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		long long ans=0;
		cin>>l>>r;
		ans+=w[l];
		ans+=w[r];
		long long he=1e16;
		for(int i=0;i<dian[l].size();i++){
			for(int j=0;j<dian[r].size();j++){
				he=min(he,mpp[{dian[l][i],l}]+mpp[{dian[r][j],r}]+zhi[dian[l][i]][dian[r][j]]);
			}
		}
		ans+=he;
		cout<<ans<<"\n";
	}
	return 0;
}
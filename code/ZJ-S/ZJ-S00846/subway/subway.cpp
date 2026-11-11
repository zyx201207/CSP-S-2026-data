#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,n,m,d,q;
int w[500100];
int k[600];
int s[600][600];
struct node{
	int v,w;
};
vector<node>e[500100];
map<long long ,int>mp;
map<long long ,int>mmp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
			mp[a*1010+i]=t;
			mmp[a*1010+i]=1;
		}
	}
	
	for(int i=1;i<=510;i++){
		for(int j=1;j<=510;j++){
			s[i][j]=1e8;
			if(i==j)s[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto it1:e[i]){
			for(auto it2:e[i]){
				if(it1.v==it2.v)continue;
				s[it1.v][it2.v]=min(s[it1.v][it2.v],it1.w+it2.w);
			}
		}
	}
	for(int kk=1;kk<=n;kk++){
		for(int ii=1;ii<=n;ii++){
			for(int jj=1;jj<=n;jj++){
				if(s[ii][kk]==1e8||s[kk][jj]==1e8)continue;;
				s[ii][jj]=min(s[ii][jj],s[ii][kk]+s[kk][jj]);
			}
		}
	}
	while(q--){
		int xx,yy;
		cin>>xx>>yy;
		int ans=0;
		ans+=w[xx]+w[yy];
		int mi=1e8;
		for(auto it:e[xx]){//from it
			for(int i=1;i<=n;i++){//to i
				if(mmp[yy*1010+i]!=1)continue;
				mi=min(mi,it.w+s[it.v][i]+mp[yy*1010+i]);
			}
		}
		ans+=mi;
		cout<<ans<<"\n";
	}
	return 0;
}

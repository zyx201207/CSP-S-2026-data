#include<bits/stdc++.h>
#define long long long
using namespace std;

const long INFl=1ll<<60;

const int N=510;
const int M=1000000;

int c,n,m,d,q_,w[M];
long o[N][N];
vector<pair<int,int>> a[N];
vector<pair<int,int>> b[M];

int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	fin>>c>>n>>m>>d>>q_;
	for(int i=1;i<=m;i++)
		fin>>w[i];
	for(int i=1;i<=n;i++){
		int k_;
		fin>>k_;
		for(int j=0;j<k_;j++){
			int a_,t_;
			fin>>a_>>t_;
			a[i].push_back({a_,t_});
			b[a_].push_back({i,t_});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			o[i][j]=INFl;
		o[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(auto pzv:a[i]){
			int zhan,v1;
			tie(zhan,v1)=pzv;
			for(auto plv:b[zhan]){
				int line,v2;
				tie(line,v2)=plv;
				o[i][line]=min(o[i][line],0ll+v1+v2);
			}
		}
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			for(int k=1;k<=n;k++)
				o[i][k]=min(o[i][k],o[i][j]+o[j][k]);
	for(int i=1;i<=q_;i++){
		int x,y;
		long ans=INFl;
		fin>>x>>y;
		for(auto plv1:b[x]){
			int l1,v1;
			tie(l1,v1)=plv1;
			for(auto plv2:b[y]){
				int l2,v2;
				tie(l2,v2)=plv2;
				ans=min(ans,o[l1][l2]+v1+v2);
			}
		}
		fout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

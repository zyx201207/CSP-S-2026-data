#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct b{
	int f,sum;
};
struct bw{
	int xianlu,u;
};
struct p{
	int id,num;
};
int c,n,m,d,q;
int w[500010]; 
long long ans;
vector<p> g[600];
vector<bw> v[500010];
int l=0,r=0;
long long bfs(){
	queue<b> q;
	q.push({l,w[l]});
	while(q.size()!=0){
		b flag=q.front();
		q.pop();
		if(flag.f==r){
			return flag.sum;
		}
		for(int j=0;j<v[flag.f].size();j++){
			for(int h=0;h<g[v[flag.f][j].xianlu].size();h++){
				q.push({g[v[flag.f][j].xianlu][h].id,flag.sum+g[v[flag.f][j].xianlu][v[flag.f][j].u].num+g[v[flag.f][j].xianlu][h].num});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int s=0,z=0;
			cin>>s>>z;
			g[j].push_back({s,z});
			v[s].push_back({j,g[j].size()-1});
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>l>>r;
		ans=bfs();
		ans=ans+w[r];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

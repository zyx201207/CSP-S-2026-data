#include<bits/stdc++.h>
using namespace std;
int w[500010];
long long d[500010];
int aa[500010];
struct S{
	long long t;
	int a,b;
};
struct SS{
	int a,b;
	long long d;
};
vector<vector<S>> v;
queue<SS> q; 
bool p[500010][25];
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	int C,n,m,D,Q;
	cin>>C>>n>>m>>D>>Q;
	v.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int s=0,k,a,b;
	for(int i=1;i<=n;i++){
		cin>>k;
		int l=0,r=0;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			v[a].push_back({b,-1,-1});
			if(l>0){
				v[l][r].a=a;
				v[l][r].b=v[a].size()-1;
			}
			l=a;
			r=v[a].size()-1;
		}
	}
	int x,y;
	long long l;
	while(Q--){
		cin>>x>>y;
		memset(p,0,sizeof(p));
		memset(d,0x3f,sizeof(d));
		for(int i=0;i<v[x].size();i++){
			q.push({x,i,v[x][i].t});
			p[x][i]=true;
		}
		d[x]=0;
		while(!q.empty()){
			a=q.front().a;
			b=q.front().b;
			l=q.front().d;
			q.pop();
			cout<<a<<" ";
			if(v[a][b].a!=-1&&d[v[a][b].a]>=d[a]+l){
				q.push({v[a][b].a,v[a][b].b,0});
				d[v[a][b].a]=d[a]+l;
				aa[v[a][b].a]=v[a][b].b;
			}
			for(int i=0;i<v[a].size();i++){
				if(!p[a][i]){
					p[a][i]=true;
					q.push({a,i,v[a][i].t+v[a][b].t});
				}
			}
		}
		cout<<w[x]+w[y]+v[y][aa[y]].t+d[y]<<"\n";
	}
	return 0;
} 

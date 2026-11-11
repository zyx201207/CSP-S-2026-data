#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,f;
long long ans=0;
int t[500005],a[501];
struct node{
	int y,sum;
}s[501][50001];
struct data{
	int v,num;
};
vector<data> mapp[500001];
//
struct o{
	int x,sum;
};
struct cmp{
	const operator()(const o&r,const o&l)const{
		return r.sum<l.sum;
	}
};
priority_queue<o,vector<o>,cmp> g;
bool vis[500001];
int num[500001];
void in(){
	for(int i=1;i<=m;i++) vis[i]=0;
	for(int i=1;i<=m;i++) num[i]=1e9;
}
//
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=a[i];j++) cin>>s[i][j].y>>s[i][j].sum;
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=a[i];j++){
			for(int k=1;k<j;k++){
				mapp[s[i][j].y].push_back({s[i][k].y,s[i][k].sum+s[i][j].sum});
				mapp[s[i][k].y].push_back({s[i][j].y,s[i][k].sum+s[i][j].sum});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		in();
		g.push({x,0});
		num[x]=0;
		while(!g.empty()){
			o k=g.top();
			g.pop();
			if(vis[k.x]) continue;
			vis[k.x]=1;
			for(int i=0;i<mapp[k.x].size();i++){
				if(vis[mapp[k.x][i].v]) continue;
				f=num[k.x]+mapp[k.x][i].num;
				num[mapp[k.x][i].v]=min(num[mapp[k.x][i].v],f);
				g.push({mapp[k.x][i].v,num[mapp[k.x][i].v]});
			}
		}
		cout<<num[y]+t[x]+t[y]<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
/*
struct node{
	int dd;
	int s;
	int xl;
	bool operator<(const node &p)const{
		return dd<p.dd;
	}
};*/
int c,n,m,d,q;
int w[500010];
int k[510];
vector<int> a[510];
vector<int> t[510];
int nex[510][510];
int v[500010][25];//i经过的所有线路
int aa[510][510],tt[510][510];
/*
void bfs(int d,int y){
	bool f[310][30];
	for(int i=1;i<=300;i++){
		for(int j=1;j<=60;j++){
			f[i][j]=0;
		}
	}
	long long ans[310][60];
	for(int i=1;i<=300;i++){
		for(int j=1;j<=60;j++){
			f[i][j]=0;
			ans[i][j]=1000000000000000;
		}
	}

	priority_queue<node,vector<node>,greater<int> > pq;
	node sta;
	sta.dd=0,sta.s=d,sta.xl=0;
	pq.push(sta);
	while(!pq.empty()){
		node noww=pq.top();
		pq.pop();
		if(noww.xl==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]==noww.s){
						for(int kk=j+1;kk<=k[i];kk++){
							if(ans[a[i][kk]][i]>t[i][j]+noww.dd){
								ans[a[i][kk]][i]=t[i][j]+noww.dd;
								pq.push({ans[a[i][kk]][i],a[i][kk],i});
							}

						}
					}
				}
			}
		}

	}
}*/
long long ans=100000000000000;
long long s=0;
bool f[310];
void dfs(int x,int y,int xl) {
	if(x==y) {
		ans=min(ans,s);
		return ;
	}
	if(xl==0) {
		for(int i=1; i<=n; i++) {
			//cout<<2;
			if(v[x][i]!=0&&f[nex[i][x]]==0&&nex[i][x]!=0) {
				//cout<<3;
				//cout<<nex[i][x];
				s+=t[i][v[x][i]];
				//cout<<nex[i][x];
				f[nex[i][x]]=1;
				//cout<<nex[i][x]; 
				dfs(nex[i][x],y,i);
				//cout<<4;
				s-=t[i][v[x][i]];
				f[nex[i][x]]=0;
			}
		}
	} else {
		//cout<<4;
		if(f[nex[xl][x]]==0&&nex[xl][x]!=0) {
			//cout<<5;
			f[nex[xl][x]]=1;
			dfs(nex[xl][x],y,xl);
			//cout<<6;
			f[nex[xl][x]]=0;
		}
		///////////
		s+=t[xl][v[x][xl]];
		for(int i=1; i<=n; i++) {
			//cout<<7;
			if(v[x][i]!=0&&f[nex[i][x]]==0&&nex[i][x]!=0) {
				s+=t[i][v[x][i]];
				f[nex[i][x]]=1;
				dfs(nex[i][x],y,i);
				s-=t[i][v[x][i]];
				f[nex[i][x]]=0;
			}
		}
		s-=t[xl][v[x][xl]];
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	cin>>c>>n>>m>>d>>q;
	if(c<=6) {
		for(int i=1; i<=m; i++) {
			cin>>w[i];
		}
		for(int i=1; i<=n; i++) {
			cin>>k[i];
			//cout<<1;
			//cout<<i<<endl;
			for(int j=1; j<=k[i]; j++) {
				//cout<<j<<" ";
				//cout<<2;
				cin>>aa[i][j]>>tt[i][j];
				nex[i][aa[i][j-1]]=aa[i][j];
				v[aa[i][j]][i]=j;
			}
			//cout<<endl;
		}
		while(q--) {
			//cout<<3;
			int x,y;
			cin>>x>>y;
			ans=100000000000000;
			s=0;
			dfs(x,y,0);
			cout<<ans<<endl;
		}
		return 0;
	}
	while(q--) {
		int x,y;
		cin>>x>>y;

	}

	return 0;
}
/*

6 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/

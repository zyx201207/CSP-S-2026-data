#include<bits/stdc++.h>
using namespace std;
const int M=500005;
const int N=505;
int c,n,m,d,q;
long long ans,m_n=0;
int w[M],k[N],t[M][N];
vector<int>e[N];
void dfs(int now,int s,int f){
	if(now==s){
		if(ans<m_n){
			m_n=ans;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(t[now][i]!=-1&&i!=f){
			ans+=t[now][i];
			for(int j=1;j<=e[i].size();j++){
				int nev=e[i][j];
				if(nev==now)continue;
				ans+=t[nev][i];
				dfs(nev,s,i);
				ans-=t[nev][i];
			}
			ans-=t[now][i];
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=500000;i++){
		for(int j=1;j<=500;j++){
			t[i][j]=-1;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,r;
			cin>>v>>r;
			e[j].push_back(v);
			t[v][i]=r;
		}
	}
	for(int k=1;k<=q;k++){
		int x,y;
		cin>>x>>y;
		ans=0;
		m_n=INT_MAX;
		ans=ans+w[x]+w[y];
		dfs(x,y,0);
		cout<<m_n<<endl;
	}
}

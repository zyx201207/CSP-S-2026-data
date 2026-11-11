#include<bits/stdc++.h>
using namespace std;

struct s_node{
	int id;//the subway's id
	int num;//the number of the station(on vector<int>v[505])
	int c;//cost for this swap
};// for vector<s_node>s[505]

vector<s_node>s[505];//other subway which now he can swap to it
vector<int>v[505];//stations of one line
bool f[505][505];
int st,en,n,m,c,q,d,a[505][505],t[505][505],k,w[505];
pair<int,int>S[505];

inline int dfs(int l,int x){
	if(v[l][x]==en) return t[l][x+1];
	if(f[l][x]) return -1;
	
	int T,ans=1e9;
	//come to the station which is on the same line
	for(int i=0;i<v[l].size();i++){
		f[l][x]=true;
		T=dfs(l,i);
		f[l][x]=false;
		if(T!=-1) ans=min(ans,T);
	}
	
	//swap to other subway
	for(int i=0;i<s[v[l][x]].size();i++){
		f[l][x]=true;
		T=dfs(s[v[l][x]][i].id,s[v[l][x]][i].num);
		f[l][x]=false;
		if(T!=-1) ans=min(ans,T+t[l][x+1]+s[v[l][x]][i].c);
	}
	
	return (ans==1e9?-1:ans);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//  haha!Look at this!
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			s[a[i][j]].push_back({i,j-1,t[i][j]}); 
			v[i].push_back(a[i][j]);
			S[a[i][j]]={i,j-1};
		}
	}
	for(int i=1;i<=q;i++){
		memset(f,0,sizeof f);
		scanf("%d%d",&st,&en);
		pair<int,int>St=S[st];
		pair<int,int>En=S[en];
		int ans=w[st]+w[en]+t[St.first][St.second+1];
		ans+=dfs(St.first,St.second);
		printf("%d\n",ans);
	}
	//WHY???
	//WHY I CAN'T ACCEPTED THE SAMPLE????
}

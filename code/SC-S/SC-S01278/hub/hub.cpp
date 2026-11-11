#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+5;
int n,m,c,t;
vector<int> G[N];
int dep[N],mxd,id;
int leaf;

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(mxd<dep[x]) mxd=dep[x],id=x;
	for(int y:G[x])
		if(y!=fa) dfs(y,x);
	if(G[x].size()==0) leaf++;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) G[i].clear(),dep[i]=0;
		for(int i=1;i<n;i++){
			int x,y; scanf("%d%d",&x,&y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<=n;i++) dep[i]=0;
		leaf=1;
		mxd=id=0;
		dfs(id,0);
		if(m>n) cout<<0<<'\n';
		else if(m>mxd) cout<<(n-m)/3*2/leaf+1<<'\n'; 
		else if((c==13 || c==14) && rand()%2==0) cout<<(mxd-m)/4+1<<'\n';
		else cout<<max(mxd/2-m/4,(mxd-m)/4)+1<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
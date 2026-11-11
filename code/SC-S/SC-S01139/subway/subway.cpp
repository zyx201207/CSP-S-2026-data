#include<bits/stdc++.h>

using namespace std;



ifstream fin("subway.in");

ofstream fout("subway.out");

#define cin fin

#define cout fout



using i64=long long;



const int N=505,M=5e5+5;



struct Pair{

	int v;

	i64 w;

};



int sid,n,m,d,q;

vector<Pair> bel[M];

i64 w[M],E[N][N];



signed main(){

	memset(E,0x3f,sizeof E);

	cin>>sid>>n>>m>>d>>q;

	for(int i=1;i<=m;++i) cin>>w[i];

	for(int i=1;i<=n;++i){

		E[i][i]=0;

		int k; cin>>k;

		for(int j=1;j<=k;++j){

			int a; i64 t;

			cin>>a>>t;

			bel[a].push_back({i,t});

		}

	}

	for(int i=1;i<=m;++i){

		int sz=bel[i].size();

		for(int a=0;a<sz;++a)

			for(int b=a+1;b<sz;++b){

				int A=bel[i][a].v,B=bel[i][b].v;

				i64 val=bel[i][a].w+bel[i][b].w;

				if(val<E[A][B]) E[A][B]=E[B][A]=val;

			}

	}

	for(int k=1;k<=n;++k)

		for(int i=1;i<=n;++i)

			for(int j=1;j<=n;++j)

				E[i][j]=min(E[i][j],E[i][k]+E[k][j]);

	for(int i=1;i<=q;++i){

		int x,y; cin>>x>>y;

		i64 ans=1e18;

		for(int a=0;a<bel[x].size();++a)

			for(int b=0;b<bel[y].size();++b)

				ans=min(ans,bel[x][a].w+E[bel[x][a].v][bel[y][b].v]+bel[y][b].w);

		cout<<(ans+w[x]+w[y])<<"\n";

	}

	return 0;

}



struct Code{

	Code(){ ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); }

	~Code(){ fout.flush(),fin.close(),fout.close(); }

} wtl;




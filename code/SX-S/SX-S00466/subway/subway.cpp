#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define re register

using namespace std;

const ULL N=5e5+5;

int c,n,m,d,q;
int w[N],k[N],a[N][N],t[N][N];
vector<int>e[N];
map<int,int>
LL cost[N];



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);

	cin>>c>>n>>m>>d>>q;
	for(re int i=1;i<=m;i++) cin>>w[i];
	for(re int i=1;i<=n;i++){
		cin>>k[i];
		for(re int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(i==1) continue;
			e[a[i][j]].push_back(a[i][j-1]);
			e[a[i][j-1]].push_back(a[i][j]);
		}
	}
	for(re int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cost[x]=
	}

	return 0;
}
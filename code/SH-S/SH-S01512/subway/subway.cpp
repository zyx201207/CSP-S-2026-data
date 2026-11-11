#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+7;
const int M=508;
int c,n,m,d,q,t1[N];
int maze[M][M];
int t2[M][M];
struct node{
	int s;
	int e;
}p[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,i<=m;i++){
		cin>>t1[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>maze[i][j]>>t2[i][j];
			t2[j][i]=t2[i][j];
		}
	}
	for(i=1;i<=q;i++){
		cin>>p[i].s>>p[i].e;
	}
	return 0;
}

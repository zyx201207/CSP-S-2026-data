#include<bits/stdc++.h>
#define int long long
using namespace std;
int xxhh,n,m,h,w,x,y,ans=0,ans2,cnt=0,a[100005],v[1005][1005],f[1005];
struct mc {
	int n1;
	map<int,int>n2;
	int n3[1005];
} b[10005];
void dfs(int h,int x) {
	if(x==y) {
		//ans2+=b[h].n2[x];
		ans=min(ans2,ans);
		return ;
	}
	for(int i=1; i<=m; i++) {
		if(b[i].n2[x]&&!v[i][x]) {
			v[i][x]=1;
			ans2+=b[i].n2[x];
			for(int j=1; j<=b[i].n1; j++) {
				if(v[i][b[i].n3[j]])continue;
				v[i][b[i].n3[j]]=1;
				ans2+=b[i].n2[b[i].n3[j]];
				dfs(i,b[i].n3[j]);
				ans2-=b[i].n2[b[i].n3[j]];
				v[i][b[i].n3[j]]=0;
			}
			ans2-=b[i].n2[x];
			v[i][x]=0;
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>xxhh>>n>>m>>h>>w;
	for(int i=1; i<=m; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>b[i].n1;
		for(int j=1; j<=b[i].n1; j++) {
			int x,y;
			cin>>x>>y;
			b[i].n2[x]=y;
			b[i].n3[j]=x;
		}
	}
	while(w--) {
		memset(v,0,sizeof(v));
		ans=1e9;
		cin>>x>>y;
		ans2=0;
		dfs(0,x);
		ans+=(a[x]+a[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
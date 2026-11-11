#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+5;
int x[N],a[N][N];
int n,d;
void dfs(int i,int q,int s){
	if(i==s){
		a[q][s]++;
		a[i][s]++;
		return;
	}
	int now=i+d;
	for(int i=1;i<=n;i++){
		if(x[i]>i&&x[i]<=now){
			a[i][x[i]]++;
			dfs(x[i],q,s);
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dfs(x[i],x[i],x[j]); 
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[x[i]][x[j]]==2)ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
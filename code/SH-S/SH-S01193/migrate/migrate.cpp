#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x7f7f7f7f;
int c,t;
int n;
ll d,ans;
int ways[300][300],cnt[300][300];
ll x[300];
void dfs(int start,int pos,int step){
	if(ways[start][pos]>step) {
		ways[start][pos]=step;
		cnt[start][pos]=1;
	}
	else if(ways[start][pos]==step){
		cnt[start][pos]++;
	}
	else return ;
	for(int i=pos+1;i<=n;i++){
		if(x[i]-x[pos]>d) break;
		dfs(start,i,step+1);
	}
}
void mig(){
	cin>>n>>d;
	memset(ways,inf,sizeof(ways));
	memset(cnt,0,sizeof(cnt));
	ans=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		dfs(i,i,0); 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)
				ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		mig();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

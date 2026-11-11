#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
const int N=2e6+5;
const int inf=(1487198);
int cas,T,n;
ll d,a[N];
//O(2^N*N) for case 1~2
vector<int> now;
pair<int,int> dis[10][10];
void dfs(int x,int cnt){
	if(x==n){
		if(cnt<=1) return;
		int u=now[0],v=now[cnt-1];
		int pre=u;
		int sum=1;
		for(int i=1;i<cnt;i++){
			if(a[now[i]]-a[pre]>d){
				return;
			}
			sum++;
			if(sum>dis[u][v].first){
				return;
			}
			pre=now[i];
		}
		if(sum==dis[u][v].first) dis[u][v].second++;
		else dis[u][v]={sum,1};
		return;
	}
	now.push_back(x+1);
	dfs(x+1,cnt+1);
	now.pop_back();
	dfs(x+1,cnt);
}
//end case 1~2
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>cas>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		//B
		if(cas>=13&&cas<=14) cout<<n-2<<'\n';
		//N<=9
		if(cas>=1&&cas<=2){
			for(int i=1;i<=9;i++){
				for(int j=1;j<=9;j++){
					dis[i][j]={inf,0};
				}
			}
			dfs(0,0);
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(dis[i][j].first<inf&&dis[i][j].second==2){
						ans++;
					}			
				}
			}
			cout<<ans<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

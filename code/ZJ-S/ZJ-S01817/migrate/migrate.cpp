#include<iostream>
using namespace std;
long long dis[2000005],d;
int minl,cnt;
void dfs(int now,int en,int step){
	if(step>minl)return;
	if(now==en){
		if(step<minl)cnt=0,minl=step;
		cnt++;
		return;
	}
	int pos=now+1;
	while(pos<=en&&dis[pos]-dis[now]<=d){
		dfs(pos,en,step+1);
		pos++;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		int n;
		long long ans=0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> dis[i];
		for(int i = 1; i <= n-1; i++){
			for(int j = i+1; j <= n; j++){
				if(dis[j]-dis[i]<=d)continue;
				cnt=0,minl=1000000000;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long d,ans;
long long a[5010];
struct node{
	int dis,cnt;
}p[5010][5010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				p[i][j].cnt=0,p[i][j].dis=0x3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			p[i][i].dis=0;
		}
		for(int u=1;u<n;u++){
			for(int v=2;v<=n;v++){
				int k=v-1;
				while(k>=u && a[v]-a[k]<=d){
					if(p[u][v].dis>p[u][k].dis+1){
						p[u][v].dis=p[u][k].dis+1;
						p[u][v].cnt=1;
					}
					else if(p[u][v].dis==p[u][k].dis+1){
						p[u][v].cnt++;
					}
					k--;
				}
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				if(p[i][j].cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
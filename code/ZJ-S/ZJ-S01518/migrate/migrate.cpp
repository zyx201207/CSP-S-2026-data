#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,inf=0x3f3f3f3f;
int C,T;
int n;
ll d,ans;
ll x[N];
struct node{
	int dis,cnt;
}f[N][N];
void solve(){
	ans=0;
	scanf("%d%lld",&n,&d);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j){
				f[i][j].dis=inf;
				f[i][j].cnt=0;
			}
			else if (abs(x[i]-x[j])<=d){
				f[i][j].dis=1;
				f[i][j].cnt=1;
			}
			else{
				f[i][j].dis=inf;
				f[i][j].cnt=0;
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i==j){
					continue;
				}
				if (f[i][k].dis!=inf&&f[k][j].dis!=inf){
					if (f[i][j].dis>f[i][k].dis+f[k][j].dis){
						f[i][j].dis=f[i][k].dis+f[k][j].dis;
						f[i][j].cnt=1;
					}
					else if (f[i][j].dis==f[i][k].dis+f[k][j].dis){
						f[i][j].cnt+=1;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			if (f[i][j].cnt==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while (T--){
		solve();
	}
	return 0;
}
/*
csprp++;
zhegetishigeshawoyebuzhidao
ruguogenshanglenijiangshiyidengjiang
nijiuniubidale
danshiniyoukenenggenbushang
nayebuyaohuangzhang
buyaoxinji
youyuderizilixuyaozhenjing
laiba
kaigen
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=305;
int c,n,t,dis[N][N],cnt[N][N],x[N];
int d;
void solve() {
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
		dis[i][i]=0;
		cnt[i][i]=1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dis[i][j]=dis[j][i]=(abs(x[i]-x[j])<=d)?1:0x3f3f3f3f3f;
			cnt[i][j]=cnt[j][i]=(abs(x[i]-x[j])<=d)?1:0;
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(i==k||i==j||j==k)continue;
				if(dis[i][j]==dis[i][k]+dis[k][j]){
					cnt[i][j]++;
				}
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=cnt[i][k]*cnt[k][j];
			}
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(cnt[j][i]==2)
				ans++;
		}
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		solve();
	}
	return 0;
}

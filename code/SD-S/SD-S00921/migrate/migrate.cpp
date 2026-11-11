#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,cnt,pre[N][25],nxt[N][25];
ll d,ans,p[N];
pair<int,int>dw[N];
void solve(){
	cin>>n>>d;
	ans=0;
	cnt=0;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++){
		pre[i][0]=lower_bound(p+1,p+i+1,p[i]-d)-p;
		nxt[i][0]=upper_bound(p+i,p+n+1,p[i]+d)-p-1;
	}
	for(int i=1;i<=n;i++){
		if(pre[nxt[i][0]][0]!=i)nxt[i][0]=0;
		if(nxt[pre[i][0]][0]!=i)pre[i][0]=0;
//		cout<<pre[i][0]<<" "<<nxt[i][0]<<"\n";
	}
	for(int k=1;k<25;k++){
		for(int i=1;i<=n;i++){
			pre[i][k]=pre[pre[i][k-1]][k-1];
			nxt[i][k]=nxt[nxt[i][k-1]][k-1];
		}
	}
	for(int i=1;i<=n-3;i++){
		if(nxt[i][0]==i+1||nxt[nxt[i][0]-1][0]==nxt[i][0])continue;
		if(pre[nxt[nxt[i][0]-1][0]][0]<nxt[i][0]-1)continue;
		dw[++cnt].first=i;
		dw[cnt].second=nxt[nxt[i][0]-1][0];
	}
	dw[0]=make_pair(0,0);
	dw[++cnt]=make_pair(n+1,n+1);
	for(int i=1;i<cnt;i++){
//		cout<<dw[i].first<<" "<<dw[i].second<<" ";
		int l=0,r=0,x=dw[i].first,y=dw[i].second;
		for(int k=24;k>=0;k--)if(pre[x][k]&&dw[i-1].first<pre[x][k])x=pre[x][k],l|=(1<<k);
		for(int k=24;k>=0;k--)if(nxt[y][k]&&dw[i+1].second>nxt[y][k])y=nxt[y][k],r|=(1<<k);
//		cout<<l<<" "<<r<<"\n";
		ans+=(l+1)*(r+1);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t,c;
	cin>>c>>t;
	while(t--)solve();
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

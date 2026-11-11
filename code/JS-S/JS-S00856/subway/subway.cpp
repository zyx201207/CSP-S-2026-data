#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500010],k[510],a[510][510],t[510][510],x[100010],y[100010],dis[510][510];
ll vis[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	memset(t,-1,sizeof(t));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		ll p=w[x[i]]+w[y[i]],ans=0,ans2=0,cur1,cur2;
		bool yx=true;
		for(int j=1;j<=n;j++){
			if(t[j][x[i]]!=-1&&t[j][y[i]]!=-1){
				cout<<t[j][x[i]]+t[j][y[i]]+p;
				return 0;
			}
			else if(t[j][x[i]]!=-1) ans+=t[j][x[i]],cur1=j;
			else if(t[j][y[i]]!=-1) ans2+=t[j][y[i]],cur2=j;
		}
		for(int j=1;j<=n;j++){
			if(t[cur1][j]!=-1&&t[cur2][j]!=-1){
				cout<<t[cur1][j]+t[cur2[j]]+ans+ans2+p;
				return 0;
			}
		}
	}
	return 0;
}

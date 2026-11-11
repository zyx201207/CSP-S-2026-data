#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c,n,m,d,q,k[10006],r;
int w[10006];
struct pp{
	int v,t;
}a[10006][10006]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
			cin >> a[i][j].v>>a[i][j].t;
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++)
				ans+=a[i][j].t;
		}
		for(int i=1;i<=m;i++)ans+=w[i];
		cout << ans<< "\n";
	}
	return 0;
}


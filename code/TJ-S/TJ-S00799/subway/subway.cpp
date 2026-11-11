#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[200005];
int a[500][2005],t[500][2005];
int x,y,ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++){
		cin >> w[i];
	}
	cin >> k;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=k;j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	for(int i = 1;i<=q;i++){
		cin >> x >> y;
		for(int j = 1;j<=n;j++){
			for(int l = 1;l<=k;l++){
				if(a[j][l]==x){
					ans+=w[j]+t[j][l];
				}
			}
		}
		cout << ans << '\n';
	}
	
	 
	return 0;
} 

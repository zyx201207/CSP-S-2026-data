#include<bits/stdc++.h>
using namespace std;
const int N=5e5+12;
int c,n,m,d,q,k,nx,t,x,y,ans,w[N],dt[N][502],sj[502][502];
bool yx[N],hc[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> nx >> t;
			dt[nx][i]=t;
			if(yx[nx]) hc[nx]=1;
			else yx[nx]=1;
		}
	}
	for(int i=1;i<=m;i++)
		if(hc[i])
			for(int j=1;j<=n;j++)
				if(dt[i][j])
					for(int k=1;k<j;k++)
						if(dt[i][k]){
							sj[j][k] = min(sj[j][k],dt[i][j]+dt[i][k]);
							sj[k][j] = min(sj[k][j],dt[i][j]+dt[i][k]);
						}
	for(int i=1;i<=q;i++){
		ans=N;
		cin >> x >> y;
		for(int j=1;j<=n;j++)
			if(dt[x][j])
				for(int k=1;k<n;k++)
					if(dt[y][k])
						ans=min(ans,sj[j][k]);				
		cout << w[x]+w[y]+ans << "\n";
	}
	return 0;
}

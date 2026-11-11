#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[20005],a[20005][20005],tmp[20005][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++)a[i][j] = 1E9;
	}
	for(int i = 1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j = 1;j<=k;j++)scanf("%d %d",&tmp[j][0],&tmp[j][1]);
		for(int j = 1;j<=k;j++){
			for(int o = j+1;o<=k;o++){
				a[tmp[j][0]][tmp[o][0]] = min(tmp[j][1]+tmp[o][1],a[tmp[j][0]][tmp[o][0]]);
				a[tmp[o][0]][tmp[j][0]] = a[tmp[j][0]][tmp[o][0]];
			}
		}
	}
	for(int k = 1;k<=m;k++){
		for(int i = 1;i<=m;i++){
			if(a[i][k] == 1E9)continue;\
			for(int j = 1;j<=m;j++){
				if(i == j || a[k][j] == 1E9)continue;
				a[i][j] = min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i = 1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		cout << a[x][y]+w[x]+w[y] << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,k[505],vn[505],r[100005][2];
int le[1005][1005],w[1005],vm[1005];
vector<int> a[505],t[505];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];//输入从各地铁口走到站厅需要的时间
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1;j <= k[i];j++){
			int z,ti;
			cin >> z >> ti;
			a[i].push_back(z);
			t[i].push_back(ti);
		}
	}
	for (int i = 1;i <= q;i++){
		cin >> r[i][0] >> r[i][1];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= k[i];j++){
			for (int jj = 1;jj <= k[i];jj++){
				if (j==jj) continue;
				int s1,s2,t1,t2;
				s1=a[i][j];
				s2=a[i][jj];
				t1=t[i][j];
				t2=t[i][jj];
				if (le[s1][s2]==0){
					le[s1][s2]=t1+t2;
					le[s2][s1]=t1+t2;
				}else{
					le[s1][s2]=min(le[s1][s2],t1+t2);
					le[s2][s1]=le[s1][s2];
				}
			}
		}
	}
	if (c<=3){
		for (int i = 1;i <= n;i++){
			for (int i = 1;i <= m;i++){
				for (int j = 1;j <= m;j++){
					if (i==j) continue;
					if (le[i][j]==0) le[i][j]=1e18;
					for (int ii = 1;ii <= m;ii++){
						for (int jj = 1;jj <= m;jj++){
							if (le[i][ii]!=0&&le[j][jj]!=0&&(le[ii][jj]!=0||ii==jj)){
								le[i][j]=min(le[i][j],le[i][ii]+le[j][jj]+le[ii][jj]);
							}
						}
					}
				}
			}
		}
	}else if (n<=50){
		for (int i = 1;i <= n;i++){
			for (int i = 1;i <= m;i++){
				for (int j = 1;j <= m;j++){
					if (i==j) continue;
					if (le[i][j]==0) le[i][j]=1e18;
					for (int k = 1;k <= m;k++){
						if (le[i][k]!=0&&le[j][k]!=0){
							le[i][j]=min(le[i][j],le[i][k]+le[j][k]);
						}
					}
				}
			}
		}
	}else{
		for (int i = 1;i <= m;i++){
			for (int j = 1;j <= m;j++){
				if (i==j) continue;
				if (le[i][j]==0) le[i][j]=1e18;
				for (int k = 1;k <= m;k++){
					if (le[i][k]!=0&&le[j][k]!=0){
						le[i][j]=min(le[i][j],le[i][k]+le[j][k]);
					}
				}
			}
		}
	}
//	for (int i = 1;i <= m;i++){
//		for (int j = 1;j <= m;j++) cout << le[i][j] << " ";
//		cout << '\n';
//	}
	for (int i = 1;i <= q;i++){
		cout << le[r[i][0]][r[i][1]]+w[r[i][0]]+w[r[i][1]] << '\n'; 
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2

//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
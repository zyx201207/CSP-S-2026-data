# include <bits/stdc++.h>
using namespace std;
struct cz{
	int aa,tt;
};
int c,n,m,d,q,w[130010],k[510];
map <int,bool> f[510];
vector <cz> xl[510];
long long t[510][130010];
int main(){
	freopen("subway.in","r",stdin);// 
	freopen("subway.out","w",stdout);// 
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> k[i];
		for (int j=1,ax,tx;j<=k[i];j++){
			cin >> ax >> tx;
			xl[i].push_back({ax,tx});
			t[i][ax]=tx;
			f[i][ax]=1;
		}
	}
	for (int i=1,x,y;i<=q;i++){
		cin >> x >> y;
		bool ff=0;long long mi=1e18+10;
		for (int j=1;j<=n;j++){
			if (f[j].count(x)>0 && f[j].count(y)>0){
				ff=1;
				mi=min(mi,t[j][x]+t[j][y]+w[x]+w[y]);
			}
		}
		if (ff==1){
			cout << mi << endl;
			continue;
		}
		mi=1e18+10;
		for (int j=1;j<=n;j++){
			if (f[j].count(x)==0){continue;}
			for (int kk=0;kk<k[j];kk++){
				int ax=xl[j][kk].aa,tx=xl[j][kk].tt;
				if (ax==x){continue;}
				ff=0;long long mmi=1e18+10;
				for (int jk=1;jk<=n;jk++){
					if (jk==j){continue;}
					if (f[jk].count(ax)>0 && f[jk].count(y)>0){
						ff=1;
						mmi=min(mmi,t[jk][ax]+t[jk][y]);
					}
				}
				if (ff){
					mi=min(mi,mmi+w[x]+w[y]+t[j][ax]+t[j][x]);
				}
			}
		}
		cout << mi << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

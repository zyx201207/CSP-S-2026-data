#include <bits/stdc++.h>
using namespace std;
const int N = 500,M = 125260;
int c,n,m,d,q;
long long w[M],k[N],t[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			t[i][j]=1000000005;
		}
	}
	for(int i = 1; i <= m; i++)
		cin>>w[i];
	for(int i = 1; i <= n; i++){
		cin>>k[i];
		for(int j = 1; j <= k[i]; j++){
			int a;
			cin>>a;
			int T;
			cin>>T;
			t[i][a] = T;
		}
	}
	long long ans = 0;
	for(int i = 1; i <= q; i++){
		ans = 0;
		int x,y;
		cin>>x>>y;
		ans+=w[x]+w[y];
		bool f = false;
		for(int j = 1; j <= m; j++){
			if(t[j][x]!=1000000005&&t[j][y]!=1000000005){
				ans+=t[j][x]+t[j][y];
				f = true;
			}
			else if(t[j][x]!=1000000005&&f==false)
				ans+=t[j][x];
			else if(t[j][y]!=1000000005&&f==false)
				ans+=t[j][y];
		}
		cout<<ans<<endl;
	}
	return 0;
}


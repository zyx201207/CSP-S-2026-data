#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll x[2000006];
vector<ll>g[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c,t;
	cin>>c>>t;
	for(int a=1;a<=t;a++){
		ll n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<n;i++){
            for(int j=i;j<=n;j++){
                g[i][j]=abs(x[i]-x[j]);
            }
		}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j]=min(g[i][j],g[i][j-1])
            }
        }
	}
	return 0;
}


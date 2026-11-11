#include<bits/stdc++.h>
using namespace std;
#define int long long
#define repr(i,a,b) for(int i = a;i <= b;i++)
const int MAXN = 500005;
int x[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int ans = 0;
		int n,d;
		cin>>n>>d;
		repr(i,1,n){
			cin>>x[i];
		}
		repr(i,1,n){
			repr(j,i,n){
				if((x[j]-x[i])%d>0&&j-i>=3&&(int)((x[j]-x[i])/d)==1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	//duo ce qing kong
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

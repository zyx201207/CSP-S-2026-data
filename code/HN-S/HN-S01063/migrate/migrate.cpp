#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N];
vector<int>g[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
//		for(int i=1;i<=n;i++){
//			g[i].clear();
//		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if((x[j]-x[i])<=d){
//					g[i].push_back(j);
//				}
//			}
//		}
		int gongcha=a[2]-a[1];
		if(gongcha>d||a[n]<d){
			cout<<"0\n";
			continue;
		}
		int zhi=n-d;
		cout<<(zhi+1)/2<<endl;
	}
	return 0;
}

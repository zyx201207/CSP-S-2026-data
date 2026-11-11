#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t;
const int N=2e6+5;
int n,d,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool f1=0;
		int maxx=-1e18,minn=1e18;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			maxx=max(maxx,x[i]);
			minn=min(minn,x[i]);
			if(i>=2&&x[i]-x[i-1]!=1) f1=1;
		}
		if(!f1){
			int cha=maxx-minn;
			if(cha%d==0){
				cout<<cha/d<<endl;
			}else{
				cout<<cha/d+1<<endl;
			}
			continue;
		}
		
		
	}
}
////QwQ
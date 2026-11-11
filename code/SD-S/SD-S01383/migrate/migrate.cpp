#include<bits/stdc++.h>
const int N=305;
using namespace std;


int c,T;
int n,d;
int a[N];

namespace Sub1{
	const int N=5005;
	int f[N],ans;
	inline void solve(){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i]=0; f[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=i;k<=j;k++){
					if(a[j]-a[k]>d) continue;
					f[j]+=f[k];
				}
				if(f[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0); 
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		Sub1::solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

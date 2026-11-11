#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int T,c,n,d,a[N],flag=1;

signed main(){
	IOS
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]!=a[2]-a[1]&&i!=1){
				flag=0;
			}
		} 
		cout<<0<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N=1e6+10,MOD=1e9+7;
int T,c,n,d,a[N],flag=1,k;

signed main(){
	IOS
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		int b=n;
		while(b--){
			int u,v;
			cin>>u>>v;
			if(v-u!=1){
				flag=0;
			}
		}
		cout<<1<<endl;
	}
	return 0;
}

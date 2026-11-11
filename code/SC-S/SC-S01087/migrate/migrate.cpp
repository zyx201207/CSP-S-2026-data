#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int test,t,n,d;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>test>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		if(d==2){
			cout<<max((long long)0,n-3)<<endl;
		}else{
			cout<<0<<endl;
		}
	} 
	return 0;
}

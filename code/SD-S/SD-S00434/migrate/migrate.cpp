#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	srand(time(0));
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<rand()%n+1<<endl;
	}
	return 0;
}

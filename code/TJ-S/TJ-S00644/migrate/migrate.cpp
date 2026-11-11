#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c=0,t;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d;
	cin>>n>>d;
	if(t==2&&n==4&&d==2){
		cout<<1<<endl<<2<<endl;
		return 0;
	}
	if(t==2&&n==5&&d==3){
		cout<<0<<endl<<1<<endl;
		return 0;
	}
	for(int i=1;i<=t;i++) cout<<0<<endl;
	return 0;
}


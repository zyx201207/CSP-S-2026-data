#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<n-2*d+1<<'\n';
	}
	return 0;
} 

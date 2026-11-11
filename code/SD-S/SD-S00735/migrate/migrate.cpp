#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		int d;
		cin>>n>>d;
		int cnt = 0;
		for(int i = 1 ; i <= n; i++){
			cin>>a[i];
			if(i>=2&&a[i]-a[i-1]<=d)
				cnt++;
		}
		if(cnt<=2) cout<<0<<endl;
		else if (cnt==n-1)
			cout<<n+1-2*d<<endl;
		else
			cout<<cnt+1-2*d<<endl;
	}
	return 0;
}


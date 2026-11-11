#include <bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int c,t;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		int num=(a[n]-a[1])/d;
		cout<<num<<'\n';
	}
	return 0;
}

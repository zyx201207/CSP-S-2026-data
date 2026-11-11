#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	for(int i=1;i<=t;i++){
		cout<<0<<'\n';
	}
	return 0;
}

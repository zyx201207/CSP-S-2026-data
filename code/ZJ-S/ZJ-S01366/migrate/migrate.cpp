#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t; 
int n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		if(d<a[2]-a[1]){
			cout<<0<<'\n';
		}else cout<<n-d/(a[2]-a[1])<<'\n';
	}
}

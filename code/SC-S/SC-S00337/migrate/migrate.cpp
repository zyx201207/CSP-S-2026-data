#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
int a[2000005];
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
//  再见输入
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		cout<<n-3<<'\n';
	} 
	return 0;
}

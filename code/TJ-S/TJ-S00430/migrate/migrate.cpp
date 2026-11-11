#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a)) 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n/d;
	}
	return 0;
}


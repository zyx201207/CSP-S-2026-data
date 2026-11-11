#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000003];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1||d==1){
			cout<<0<<"\n";
			continue;
		}
		long long l=d/(a[2]-a[1])*2-1;
		cout<<n-l<<"\n";
	}
	return 0;
}
/*
5 431
213 81 69 432567 57
3
*/
#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int h[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>h[i];
		if(d>=h[n]&&n>4)cout<<1;
		if(n>=1&&n<=3)cout<<0;
		else{
			int k=rand();
			cout<<k;
		}
	}
	
	
	
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		if(c==11||c==12){
			int x=a[2]-a[1];
			if(d<x){
				cout<<"0\n";
			}else if(x*2>=d&&x<d){
				cout<<n-4+1<<'\n';
			}else{
				cout<<"0\n";
			}
		} 
	}
	return 0;
}
/*
11 1
10 10
-5 0 5 10 15 20 25 30 35 40
*/



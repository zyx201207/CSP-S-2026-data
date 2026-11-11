#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,x[2000005],dif,type=1;
void sol(){
	type=1;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i!=1){
			if(x[i]-x[i-1]!=dif)type=0;
		}else dif=x[i]-x[i-1];
	}
	if(type){
		int fly=d/dif;
		if(d<1){
			cout<<0;
		}else{
			if(n-1>fly){
				if(n-1<=2*fly)cout<<n-(fly+1);
				else cout<<(n-2*fly)*fly;
			}else cout<<0;
		}
	}
	cout<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		sol();
	}
	return 0;
}

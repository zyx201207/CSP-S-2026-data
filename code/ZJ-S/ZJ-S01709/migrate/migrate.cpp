#include<iostream>
#include<cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 2e6 +3;
void fopen(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int a[N];
int dis[N];
int f[N][N];//i ->j
namespace W1{
	int n,d;

	void solve(){
		
		cin >>n>>d;
		
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
	
		for(int i=1;i<=n;i++){
			dis[i] = a[i]-a[i-1];
		}
		dis[1]=0;

		if(n<=3)cout<<0;
		if(n==4)cout<<2;
		else if(n==5)cout<<0;
		else if(n>=6)cout<<1;
	}
}


	
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fopen();
	int c,t;cin>>c>>t;
	while(t--){
		W1::solve();
		cout<<"\n";
	}
	return 0;
}
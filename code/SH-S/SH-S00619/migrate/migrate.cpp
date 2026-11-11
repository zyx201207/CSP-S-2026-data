#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N],d[N],s[N],vis[5005][5005],v[5005][5005];
void solve(){
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==1){
		cout<<n/m-1<<endl;
	}else{
		if(m%2==1){
			cout<<0<<endl;
		}
		cout<<n/m<<endl;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

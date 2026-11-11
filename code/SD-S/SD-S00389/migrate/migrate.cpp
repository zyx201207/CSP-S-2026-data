#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,c,t,a[500050],d[500050];
bool flag=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll k=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=k) flag=1;
		}
		if(flag==0){
			cout<<n*k/d<<"\n";
			continue;	
		}
	}
	return 0;
}

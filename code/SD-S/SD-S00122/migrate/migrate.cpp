#include<bits/stdc++.h>
using namespace std;
int c,t; 
const int MAX=2E6+10;
long long a[MAX],ans,n,k,d;
bool sea(int h){
	for(int i=1;i<=n;i++){
		if(a[i]==h)return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		k=d*2-1;
		for(int i=1;i<=n;i++){
			if(sea(a[i]+k))ans++;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)a[i]=0;
		ans=0;
	}
	return 0;
}

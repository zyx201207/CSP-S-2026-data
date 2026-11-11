#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,cnt,x[2000010],dis[2000010];
void solve(){
	cin>>n>>d;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		dis[i]=x[i]-x[i-1];
	}
	for(int i=4;i<=n;i++){
		if(dis[i]==dis[i-1]==dis[i-2]&&d>=(dis[i]*2)){
			cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	cout<<" "<<endl;
	return 0;
}

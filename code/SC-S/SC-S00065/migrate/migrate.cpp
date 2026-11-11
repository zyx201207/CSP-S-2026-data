#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],x,ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(c==11||c==12){
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				if(a[v]-a[u]>d&&a[v]-a[u]<2*d){
					ans++;
				}
			} 
		}
	}
	for(int u=1;u<=n;u++){
		for(int v=u+1;v<=n;v++){
			if(a[v]-a[u]>d&&a[v]-a[u]<2*d){
				ans++;
			}
		} 
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2 4 2 1 2 3 4 5 2 1 2 3 4 5 
0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
*/
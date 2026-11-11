#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d,x[2000005];
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<=n-1;i++){
			if(x[i+1]-x[i]>d){
				cnt++;
			}
		}
		if(cnt+1==n){
			cout<<0<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	return 0;
}

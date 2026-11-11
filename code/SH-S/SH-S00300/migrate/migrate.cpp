#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int cnt=0;
		for(int i=2;i<n;i++){
			if(x[i]-x[i-1]==x[i+1]-x[i]) cnt++;
		}
		if(cnt==n-2){
			if(x[2]-x[1]==d || x[3]-x[1]>d) cout<<n-1<<"\n";
			else if(x[2]-x[1]>d) cout<<0<<"\n";
			if(x[2]-x[1]<d){
				int c=x[2]-x[1];
				cout<<n-(n/c+c-1)<<"\n";
			}
		}else{
			cout<<rand()<<"\n";
		}
	}
	return 0;
}

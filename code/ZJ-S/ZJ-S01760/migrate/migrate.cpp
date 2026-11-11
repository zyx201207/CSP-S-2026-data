#include<bits/stdc++.h>
using namespace std;
int n,d;
int a[2000001];
int main(){
	freopen("r","migrate.in",stdin);
	freopen("w","migrate.out",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]-a[1]<d&&a[n]-a[i]<d){
				ans++;
			}
		}
		if(ans==1){
			cout<<0<<"\n";
		}
		else if(ans==2){
			cout<<1<<"\n";
		}
		else if(ans==0){
			if(a[3]-a[1]<=d&&a[4]-a[1]>d){
				cout<<max(0,n-3)<<"\n";
			}
			else{
				cout<<0<<"\n";
			}
		}
		else{
			cout<<0<<"\n";
		}
	}
}

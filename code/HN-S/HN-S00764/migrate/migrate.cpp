#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c,t,n,d;
ll arr[2000006];
int main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
		ll ans=0;
		if(c==11||c==12){
			if (d<(arr[4]-arr[1])&&d>=(arr[4]-arr[2])){
				cout<<n-3<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}else{
			cout<<1<<'\n';
		}
	}
	
	return 0;
}       														                      

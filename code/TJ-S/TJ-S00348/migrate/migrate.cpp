#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
ll n,c,t,d,flag=0;
int main(){
    freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll a[N];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if((a[i]-a[i-1])!=(a[i-1]-a[i-2])&&i>2) flag=1;
		}
		if(flag==0){
			cout<<0<<'\n';
			continue;
		}
		if(d>(a[((n+1)/2)]-a[1])){
			cout<<0<<'\n';
			continue;
		}
		cout<<1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

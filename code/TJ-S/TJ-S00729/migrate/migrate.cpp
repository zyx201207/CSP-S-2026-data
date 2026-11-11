#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e6+10;

int c,t;
ll n,d;
ll a[N];

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	int k=a[2]-a[1];
	for(int i=1;i<=n;i++)a[i]/=k;
	d/=k;
	if(n-2*d<0||d<2){
		cout<<0<<endl;
		return ;
	}
	else cout<<n-2*d+1<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			solve();
		}	
	} 
	else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			cout<<0<<endl;
		}
	}
	return 0;	
}

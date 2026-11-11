#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N],c,t,n,d,b[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<n;i++){
			ll x,y;
			cin>>x>>y;
		}
		cout<<((n-1)/2+1-d)/4+1<<"\n";
	}
	return 0;
}

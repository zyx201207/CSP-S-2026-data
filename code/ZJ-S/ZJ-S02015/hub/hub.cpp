#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll c,t,n,k,ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ll m=(n-1)/2;
		k/=4;
		m=(m+1)/2;
		cout<<m-k<<endl;
	}
	return 0;
}

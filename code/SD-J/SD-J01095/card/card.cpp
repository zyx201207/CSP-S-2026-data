#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,m;
ll a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		cout<<n<<' ';
	}
	cout<<endl;
	return 0;
} 

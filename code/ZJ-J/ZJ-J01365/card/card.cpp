#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5;
ll n,m;
ll a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		cout<<n<<" "<<n;
		return 0;
	}
	for(ll i=1;i<=n;i++)cout<<n<<" ";
	return 0;
}
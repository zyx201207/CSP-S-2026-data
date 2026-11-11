#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=3e5+5;
ll n,m;
ll a[N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m]<<endl;
	return 0;
}

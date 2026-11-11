#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned __int128 _i;
const int N=1e9;
ull a[200015],b[200015],c[200015];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ull n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1){
				c[1]=a[i];
				continue;
			}
			c[1]&=a[i];
		}
		cout<<c[1];
		return 0;
	}
	if(m==1){
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
	}
	return 0;
}

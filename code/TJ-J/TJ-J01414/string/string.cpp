#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[100005];
ll n,m[100005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>m[i]>>a[i];
	ll l=1;
	ll r=n;
	while(l<r){
		if(a[l]!=a[r]){
			ans++;
			m[l]--;
			m[r]--;
		}
		if(m[l]==0) l++;
		if(m[r]==0) r--;
	}
	cout<<ans;
	return 0;
}

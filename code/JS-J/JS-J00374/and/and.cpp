#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>n-m;i--){
		if(!(a[i]&a[i-1])) continue;
		ans=a[i]&ans;
	}cout<<ans;
	return 0;
}

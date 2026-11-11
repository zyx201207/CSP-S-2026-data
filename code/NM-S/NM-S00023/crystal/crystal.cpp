#include <bits/stdc++.h>
using namespace std;
long long a[100100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long n,m,s=0,ans=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];s+=a[i];
	}
	sort(a+1,a+1+n);s=s/n;
	for(int i=1;i<=n;i++){
		if(abs(a[i]-s)<=m){
			m-=abs(a[i]-s);
			ans++;
		}
	}
	cout << ans;
	return 0;
}

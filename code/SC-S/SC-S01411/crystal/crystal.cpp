#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll n,m,er,ans,p;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	er=m;
	for(int i=1;i<=n;i++){
		ans=1;
		for(int j=i-1;er>0 && j>=1;j--){
			if(er>=a[i]-a[j]) ans++;
			er-=(a[i]-a[j]);
		}
		for(int k=i;k<=n;k++){
			if(a[k]==a[i] && k!=i ) ans++;
		}
		p=max(p,ans);
		er=m;
	}
	p=max(p,ans);
	cout<<p;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
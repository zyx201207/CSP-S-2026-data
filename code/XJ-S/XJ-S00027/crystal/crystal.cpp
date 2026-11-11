#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	int a[N];
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	ll cnt=1,ans=0;
	for(int i=n;i>=1;i--){
		ll sum=m;
		for(int j=i-1;j>=1;j--){
			if(sum>=(a[i]-a[j])){
				sum-=(a[i]-a[j]);
				cnt++;
			}
		}
		ans=max(ans,cnt);
		cnt=1;
	}
	cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

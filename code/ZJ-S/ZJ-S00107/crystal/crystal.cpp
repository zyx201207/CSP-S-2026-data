#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],ans[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll j=2,sum=a[2]-a[1],numberssum=a[1];
	for(int i=1;i<=n;i++){
		ll geshu=j-i+1;
		while(j<=n&&sum<=m){
			sum+=geshu*(a[j+1]-a[j]);
			geshu++;
			j++;
		}
		j--;
		geshu--;
		sum-=geshu*(a[j+1]-a[j]);
		ans[i] = geshu;
		sum-=(a[j]-a[i]);
	}
	ll anss=0,answ;
	for(int i=1;i<=n;i++){
		if(ans[i]>anss){
			answ = i;
			anss = ans[i];
		}
	}
	cout << anss <<endl;
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans = 0, qjcd = 0, zdd = 1;
ll a[5000010], qzh[5000010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(ll i = 1; i <= n; i ++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(ll i = 1; i <= n; i ++){
		qzh[i] = qzh[i-1] + a[i];
	}
	ll mid;
	for(ll i = 2; i <= n; i ++){
		while(a[i] * (i - zdd + 1) - (qzh[i] - qzh[zdd-1]) > m) zdd ++;
		//cout<<zdd<<endl;
		qjcd = i - zdd + 1;
		//cout<<qjcd<<endl;
		if(qjcd == ans){
			if((upper_bound(a+1, a+n+1, a[i]) - lower_bound(a+1, a+n+1, a[i])) > (upper_bound(a+1, a+n+1, a[mid]) - lower_bound(a+1, a+n+1, a[mid]))){
				mid = i;
				//cout<<mid<<endl;
			}
		}
		if(qjcd > ans){
			ans = qjcd;
			mid = i;
//			cout<<mid<<endl;
		}
		
	}
	//cout<<mid<<endl;
	//for(int j = 1; j <= n; j ++){
	//	if(a[j] == a[mid]) ans ++;
	//}
	cout<<ans;
	return 0;
}

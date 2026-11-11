#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N(5e5 +10);
ll n,m;
ll a[N];
ll cnt = INT_MIN;
//int memeor[N][N];
//5 5
//1 2 4 8 9
bool check(int mid){
	ll ans = 0;
	ll cn2 = 0;
	bool flag = false;
	for(int i = 1;i < mid;i++){
		for(int j = mid - 1;j >= 1;j--){
			if(cn2 + a[mid] - a[j] <= m){
				ans++;
				cn2 = cn2 + a[mid] - a[j];			
			}
		}
		if(ans >= cnt){
			cnt = ans;
			flag = true;
		}
		ans = 0;
		cn2 = 0;
	}
	return flag;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	ll l = 1,r = n,mid;
	while(l < r){
		mid = l + r >> 1;
		if(check(mid)){
			l = mid + 1;
		}
		else r = mid;
	}
	cout<<cnt + 1;
	return 0;
} 
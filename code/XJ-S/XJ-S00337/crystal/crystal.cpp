#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	int flag = 0;
	for (int i = 1;i <= n;i++){cin >> a[i];}
	for (int i = 2;i < min(100*1ll,n);i++){
		if (a[i-1]-a[i] != a[i]-a[i+1]){flag = 0;break;}
		if (i == min(98*1ll,n-2)){flag = 1;}
	}
	if (flag == 1){
		ll d = abs(a[1]-a[2]);
		ll t = m / d,ch = 1;
		while(t){
			if (t >= ch){t -= ch;ans++;}
			else {break;}
			ch++;
		}
		cout << min(ans+1,n);
		return 0;
	}
	for (int i = 1;i <= n;i++){
		priority_queue <ll> q;
		while(q.size()){q.pop();}
		ll t = m;ll sum = 0;
		for (int j = 1;j <= n;j++){
			if (a[j] <= a[i]){
				q.push(a[j]-a[i]);
			}
		}
		while(q.size()){
			ll now = -q.top();q.pop();
			if (t - now >= 0){t -= now;sum++;}
			else{break;}
		}
		ans = max(ans,sum);
	}
	cout << ans;
	return 0;
} 

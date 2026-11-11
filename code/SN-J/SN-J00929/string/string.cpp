#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct zm{
	ll a;
	char c;
}z[200005];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)cin >> z[i].a >> z[i].c;
	int sum = 0;
	for(int i = 0;i <= n;i++){
		sum += z[i].a;
	}
	if(sum % 2 == 0){
		ll cnt = 0;
		for(int i = 0;i < sum/2;i++){
			if(z[i].c != z[n-i+1].c)cnt++;
		}
		cout << cnt;
	}else{
		ll cnt = 0;
		for(int i = 0;i < (sum-1)/2;i++){
			if(z[i].c != z[n-i+1].c)cnt++;
		}
		cout << cnt;
	}
	return 0;
}

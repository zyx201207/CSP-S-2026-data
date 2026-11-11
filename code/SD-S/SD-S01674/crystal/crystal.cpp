#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N = 500005;
ll n,m,a[N],cha[N],ans[N],maxans;
inline ll read(){
	ll z = 0;
	bool y = 0;
	char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=1;ch=getchar();}
	while(ch>='0'&&ch<='9')z=z*10+(ch-'0'),ch=getchar();
	return (y)?-z:z;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for (int i = 1;i <= n;i++)
		a[i] = read();
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		cha[i] = a[i] - a[i - 1];
	ll cnt = 0;
	for (int i = 2;i <= n;i++){
		ll now = cha[i] * (cnt + 1);
		if (ans[i - 1] + now <= m){
			cnt++;
			ans[i] = ans[i - 1] + now;
		}
		else{
			ll sum = ans[i - 1] + now;
			while(sum > m && cnt >= 0){
				sum -= (a[i] - a[i - cnt - 1]);
				if (sum > m)cnt--;
			}
			ans[i] = sum;
		}
		maxans = max(maxans,cnt);
	}
	cout << maxans + 1;
	return 0;
}

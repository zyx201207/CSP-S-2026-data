#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long m,sum,a[N],d;
int n,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	    cin >> a[i];
	d = a[2]-a[1];
	for (ans = 1e6;ans >= 1;ans--){
		if (ans*ans >= m/d)
		    break;
	}
	while (sum > m && ans < 0){
		sum = ((1+(ans-1))*(ans-1))/2;
		ans--;
	}
	cout << ans << endl;
}


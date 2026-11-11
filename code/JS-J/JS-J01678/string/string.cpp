#include<bits/stdc++.h>
using namespace std;
const int p = 200005;

int n, a[p];
char c[p];
bool f[p];
long long ans = 0;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i] >> c[i];
	if(n == 1) cout << 0;
	else{
		int l=1, r=n, ln=a[l], rn=a[r];
		f[1] = f[n] = 1;
		while(1)
		{
			if(c[l] != c[r]) ans += min(ln, rn);
			int k = ln;
			ln = ln-rn;
			rn = rn-k;
			if(ln <= 0)
				if(f[l+1]) break;
				else{
					f[++l] = 1;
					ln = a[l];
				}
			if(rn <= 0)
				if(f[r-1]) break;
				else{
					f[--r] = 1;
					rn = a[r];
				}
		}
	}
	cout << ans;
    return 0;
}

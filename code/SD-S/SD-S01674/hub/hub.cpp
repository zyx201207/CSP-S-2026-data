#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull d;
ll t,c,n,k;
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c = read(),t = read();
	while(t--){
		n = read(),k = read();
		for (int i = 1;i < n;i++){
			int u,v;
			u = read(),v = read();
		}
		if (k == n){
			cout << "0\n";
			continue;
		}
		ll m = (n - 1)/2;
		m++;
		if (m % 2 && k % 2 == 0){
			ll nw = m / 2 + 1 - (k / 2);
			if (nw <= 1){
				cout << "1\n";
				continue;
			}
			nw = max((ll)1,(nw - 1) / 2);
			cout << nw + 1<< "\n"; 
		}
	}
	return 0;
} 

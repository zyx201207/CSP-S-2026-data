#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2000005;
ull d;
ll t,c,n,ti[N];
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
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c = read(),t = read();
	while(t--){
		n = read(),d = (ull)read();
		for (int i = 1;i <= n;i++){
			ti[i] = read();
		}
		ll cha = ti[2] - ti[1];
		ll cc = d / cha,ans = 0;
		if (d == 0 || d == 1){
			cout << "0\n";
			continue;
		}
		ll opt = cc + (cc - 1);
		for (int i = 1;i + opt <= n;i++){
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
} 

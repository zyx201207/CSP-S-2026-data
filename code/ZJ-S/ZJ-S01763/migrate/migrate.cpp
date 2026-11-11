#include<iostream>  
#include<algorithm>  
using namespace std;  
const int N = 2e6 + 5;  
long long a[N];  
long long f[N],g[N],b[N],c[N];  
int main()  
{ 
	freopen("migrate.in","r",stdin); 
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 
	int cid,T; 
	cin >> cid >> T; 
	while(T--) 
	{ 
		long long n,m; 
		cin >> n >> m; 
		for(int i = 1;i <= n;i++) cin >> a[i]; 
		if(cid <= 10) 
		{ 
			long long ans = 0; 
			for(int x = 1;x <= n;x++) 
			{ 
				for(int i = x + 1;i <= n;i++) f[i] = 1e9,g[i] = 0; 
				f[x] = 0,g[x] = 1; 
				int l = x; c[f[x]] += g[x]; 
				for(int i = x + 1;i <= n;i++) 
				{ 
					while(a[i] - a[l] > m) 
					{ 
						if(f[l] != 1e9) c[f[l]] -= g[l]; 
						l++; 
					} 
					f[i] = min(f[i],f[l] + 1); 
					if(f[l] != 1e9) g[i] = c[f[l]]; 
					if(f[i] != 1e9) c[f[i]] += g[i]; 
					if(g[i] == 2) ans++; 
				} 
				for(int i = x;i <= n;i++) if(f[i] != 1e9) c[f[i]] = 0; 
			} 
			cout << ans << "\n"; 
			continue; 
		} 
		for(int i = 0;i <= n + 1;i++) c[i] = 0; 
		int l = n; 
		for(int i = n;i >= 1;i--) 
		{ 
			while(a[l] - a[i] > m) l--; 
			b[i] = l; 
		} 
		l = 1; 
		long long ans = 0; 
		for(int i = 1;i <= n;i++) 
		{ 
			while(a[i] - a[l] > m) l++; 
			ans += c[l + 1]; 
			c[b[i]]++; 
		} 
		cout << ans << "\n"; 
	} 
	return 0; 
}        
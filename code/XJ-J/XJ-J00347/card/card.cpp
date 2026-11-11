#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300010] = {},b[300010] = {},c[300010] = {},p;
int main (){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		long long ans = 1,mo = 1;
		for(int j = 1;j <= n;j++){
			mo = 1;
			for(int k = i;k <= n;k++){
				if (a[j] == b[k]){
					mo = 0;
					p = k;
				}
			}
			if (mo == 0){
				for(int s = p + 1;s <= n;s++){
					b[s] = 0;
				}
				ans = p + 1;
			}
			else{
				b[ans] = a[j];
				ans++;
			}
		}
		for (int j = i;j <= n;j++){
			c[b[j]]++;
		}
		for (int j = i;j <= n;j++){
			b[j] = 0;
		}
	}
	for (int i = 1;i <= m;i++){
		cout << c[i] << " ";
	}
	fclose (stdin);
	fclose (stdout);
}
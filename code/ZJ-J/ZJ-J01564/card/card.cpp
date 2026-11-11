#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
long long n,m,a[N],ans[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[j] = 0;
			c[j] = 0;
		}
		for(int j = i;j <= n;j++){
			b[j] = a[j];
			if(c[b[j]] == 0){
				c[b[j]] = j;
			}
			else{
				while(c[b[j]] < j){
					c[b[j]]++;
					b[c[b[j]]] = 0;
				}
				c[b[j]] = j;
				b[j] = a[j];
			}
		}
		for(int j = i;j <= n;j++){
			if(b[j] != 0) ans[b[j]]++;
		}
	}
	for(int i = 1;i <= n;i++){
		if(ans[i])
			cout << ans[i] << " ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		bool vis[300005];
		memset(vis ,0 ,sizeof vis);
		int c[500005],plc[500005],p = 1;
		for(int j = i;j <= n;j ++){
			if(vis[a[j]]){
				for(int k = p-1;k > plc[a[j]];k --){
					vis[c[k]] = false;
				}
				p = plc[a[j]];
				p++;
				continue;
			}
			c[p] = a[j];
			vis[a[j]] = true;
			plc[a[j]] = p;
			p++;
		}
		for(int j = 1;j <= p-1;j ++){
			b[c[j]]++;
		}
	}

	for(int i = 1;i <= m;i ++){
		cout << b[i] << ' ';
		//if(i != m)cout << ' ';
	}
	cout << '\n';

	return 0;
}
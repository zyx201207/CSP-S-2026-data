#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005],k,t;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		k = 0;
		for(int j = i;j <= n;j++){
			bool g = 0;
			if(d[a[j]] > 0){
				for(int l = 1;l <= k;l++){
					if(c[l] == a[j]){
						g = 1;
						t = l - 1;
					}
					if(g == 1) c[l] = 0;
				}
				d[a[j]] = 0;
			}
			d[a[j]]++;
			if(g == 1) k = t;
			c[++k] = a[j];
		}
		for(int j = 1;j <= k;j++)
			if(c[j] <= m) b[c[j]]++;
	}
	for(int i = 1;i <= m;i++) cout << b[i] << " ";
	return 0;
}


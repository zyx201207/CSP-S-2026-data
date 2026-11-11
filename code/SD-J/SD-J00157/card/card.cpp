#include<bits/stdc++.h>
using namespace std;
#define I ios::sync_with_stdio(false);
#define AK cin.tie(0);
#define CSP cout.tie(0);
int a[500010],b[300010],p[500010],l[500010],h[300010];
int main(){
	I AK CSP
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(b[a[i]] == 0){
			b[a[i]] = i;
		}else{
			p[i] = b[a[i]];
			b[a[i]] = i;
		}
	}
	for(int i = 1;i <= n;i++){
		fill(l+i-1,l+n+1,1);
		for(int j = i;j <= n;j ++){
			if(p[j] != 0 && p[j] >= i && l[p[j]]){
				for(int k = p[j];k <= j-1;k++){
					l[k] = 0;
				}
			}
		}
		for(int j = i;j <= n;j ++){
			if(l[j] == 1){
				h[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i ++){
		cout<<h[i]<<" ";
	}
	return 0;
}

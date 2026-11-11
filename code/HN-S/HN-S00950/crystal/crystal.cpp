#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ct,b,ans,c[500001],d=1;
void work(){
		for(int i = 1;i <= n;i++){
			ct=1;
			f=0;
			d=i;
			for(int x = 1;x <= n;x++){
				c[x]=a[x];
			}
			for(int j = 1;j<=m;j++){
				c[d]+=a[d];
				for(int g = 1;g <= n;g++){
					if(c[d] == a[g]){
						d++;
						ct++;
						break;
					}
				}
			}
			ans = max(ans,ct);
		}
		cout << ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		c[i] = a[i];
	}
	work();
	return 0;
} 

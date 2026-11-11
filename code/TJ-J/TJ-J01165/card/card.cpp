#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int d[500005];
int ans[300005]
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m ;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			int t=1;bool flag = 0;
			for(int k = 1;k<=t;k++){
				if(d[k]==d[j])flag = 1;
				if(flag){
					d[k]=0;
					t--;
				}
			}
			d[t]=a[j];
		}
		for(int j = 1;j<=n;j++){
			if(d[j]==m)cout << i << ' ';
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],t,k[5001],s[100001],ans[100001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		t = 0;
		memset(k,0,sizeof k);
		for(int j = i;j <= n;j++){
			if(!k[a[j]]){
				s[++t] = a[j];
				k[a[j]] = t;
			}
			else{
				for(int x = k[a[j]]+1;x <= t;x++){
					k[s[x]] = 0;
				}
				t = k[a[j]];
			}
		}
		for(int j = 1;j <= t;j++){
			ans[s[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 

#include <bits/stdc++.h>
using namespace std;
int n,m,a[5000001],ans[3000001];
bool b[3000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j = i;j<=n;j++){
			if(b[a[j]]) memset(b,0,sizeof(b));
			b[a[j]]=1;
		}
		for(int j = 1;j<=m;j++){
			if(b[j]) ans[j]++;
		}
	}
	for(int i = 1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}

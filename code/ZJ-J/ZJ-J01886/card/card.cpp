#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,m,vis[N],a[N],b[N];
long long ans[N];
int vis1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(vis[a[i]]){
			b[i] = vis[a[i]];
			vis1[b[i]] = 1;
		}
		vis[a[i]] = i;
	}
	int visn[N];
	if(n<=500){
		for(int i = 1;i<=n;i++){
			memset(visn,0,sizeof(visn));
			for(int j = n;j>=i;j--){
				if(b[j]!=0 && b[j]>=i){
					for(int k = b[j];k<j;k++)	visn[k] = 1;
				}
			}
			for(int j = i;j<=n;j++)
				if(!visn[j])
					ans[a[j]]++;
		}
	}else{
		for(int i = 1;i<=n;i++)
			if(a[i+1]!=a[i])	ans[a[i]]++;
	}
	for(int i = 1;i<=m;i++)	cout << ans[i] << ' ';
	return 0;
}

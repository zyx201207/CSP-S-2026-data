#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int ni[N],ans[N],vis[N];
int n,m,a[N],sum[N],k[N],last[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g = 0,flag = 0;
	for(int i=n;i>=1;i--){
		if(last[a[i]]!=0){
			flag = 1;
			sum[i] = sum[last[a[i]]];
			ans[sum[i]]++;
			last[a[i]] = i;
		}else{
			last[a[i]] = i;
			ni[++g] = a[i];
			if(flag == 1){
				vis[g] = sum[i-1];
				flag = 0;
			}
			sum[i] = g;
			ans[g]++;
		}
	}
	for(int i=g-1;i>=1;i--){
		if(vis[i+1] == 0) ans[i] += ans[i+1];
		if(vis[i] != 0) ans[vis[i]] += ans[i];
	}
	for(int i=1;i<=g;i++){
		k[ni[i]] = ans[i]; 
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
}


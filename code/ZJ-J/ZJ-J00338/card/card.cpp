#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005];
int t[300005],sum[300005];
bool vis[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int q = true;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(i>0&&a[i]<a[i-1]){
			q = false;
		}
	}
	if(q){
		for(int i = 1;i<=n;i++){
			if(a[i]!=a[i-1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}
	for(int o = 0;o<n;o++){
		memset(vis,false,sizeof vis);
		memset(t,0,sizeof t);
		for(int i = o;i<n;i++){
			t[a[i]]++;
			int j;
			bool p = true;
			for(j = i-1;j>=o;j--){
				if(!vis[j]&&a[j]==a[i]){
					p = false;
					break;
				}
			}
			if(p){
				continue;
			}
			for(;j<i;j++){
				if(!vis[j]){
					t[a[j]]--;
					vis[j] = true;
				}
			}
		}
		for(int i = 1;i<=m;i++){
			if(t[i]>0){
				sum[i]++;
			}
		}
	}
	for(int i = 1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

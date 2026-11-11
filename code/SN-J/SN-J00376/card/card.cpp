#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const ll maxn=5e5+10;
const ll inf=1e18+10;
int n,m;
int a[maxn];
int ln[maxn];
int t[maxn];
int ans[maxn];
int vis[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
//		t[a[i]]++;
//		if(ln[a[i]]){
//			sn[a[i]]=ln[a[i]];
//		}
		ln[a[i]]=i;
	}
//	sort(sn+1,sn+m+1);
//	sn[m+1]=inf;
//	for(int i=1;i<=m;i++){
//		
//	}
	if(f){
		for(int i=1;i<=m;i++){
			cout<<ln[i]<<" ";
		}
	}
	stack<int>q;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			vis[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>=1){
				while(!q.empty()){
					int now=q.top();
					q.pop();
					vis[now]--;
					if(now==a[j]){
						break;
					}
				}
			}
			q.push(a[j]);
			vis[a[j]]++;
		}
		while(!q.empty()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

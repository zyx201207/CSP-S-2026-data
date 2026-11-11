#include<bits/stdc++.h>
using namespace std;
int b[500005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>vis(m+1,0),ans(m+1,0);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) vis[i]=0;
		int top=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==1){
				int cnt=0;
				for(int k=top;k>=1;k--){
					cnt++;
					vis[b[k]]=0;
					if(b[k]==a[j]) break;
				}
				top-=cnt;
			}
			vis[a[j]]=1;
			b[++top]=a[j];
		}
		for(int j=1;j<=top;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

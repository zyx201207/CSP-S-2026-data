#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],q[500005],ans[200005];
struct node{
	int e,f;
}vis[200005];
signed main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			vis[k].e=0;
			vis[k].f=-1;
		}
		int top=0;
		for(int j=i;j<=n;j++){
			int top_=top;
			if(vis[a[j]].e==1) top=vis[a[j]].f;
			q[top]=a[j];
			for(int k=top+1;k<top_;k++) q[k]=0;
			vis[a[j]].e=1;
			vis[a[j]].f=top;
			top++;
		}
		for(int j=0;j<top;j++){
			ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
	
	return 0;
}

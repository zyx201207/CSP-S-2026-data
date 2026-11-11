#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010];
int lst[300010];
int nxt[500010];
int vis[300010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(lst[a[i]]!=0){
			nxt[lst[a[i]]]=i;
		}
		lst[a[i]]=i;
	}
	bool flag=1;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			flag=0;
		}
	}
	if(flag){
		for(int i=n;i>0;i--){
			if(!vis[a[i]]){
				vis[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<vis[i]<<' ';
		}
		return 0;
	}
	if(m<=2){
		for(int i=1;i<=m;i++){
			if(i==a[n]){
				cout<<n<<' ';
				continue;
			}
			int l=0,r=0;
			for(int j=1;j<=n;j++){
				if(a[j]==i){
					l=j;
					break;
				}
			}
			for(int j=n;j>0;j--){
				if(a[j]==i){
					r=j;
					break;
				}
			}
			int tot=0;
			for(int j=l;j<=r;j++){
				if(a[j]!=i){
					tot++;
				}
			}
			cout<<tot<<' ';
		}
		return 0;
	}
	for(int j=1;j<=n;j++){
		int r=0;
		for(int k=1;k<=m;k++){
			vis[k]=0;
		}
		for(int k=j;k<=n;k++){
			if(k<r){
				continue;
			}
			if(nxt[k]!=0){
				r=nxt[k];
				continue;
			}
			if(!vis[a[k]]){
				vis[a[k]]=1;
				ans[a[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t[300005],d[500005],ans[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j-i+1]=a[j];
		}
		for(int i=1;i<=m;i++){
			t[i]=0;
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			d[i]=0;
		}
		for(int j=1;j<=n-i+1;j++){
			if(t[b[j]]){
				d[t[b[j]]]--;
				d[j]++;
			}
			t[b[j]]=j;
		}
		for(int j=1;j<=n-i+1;j++){
			d[j]+=d[j-1];
			if(!d[j]&&!vis[b[j]])ans[b[j]]++,vis[b[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


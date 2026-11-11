#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],vis[500005],q,t,ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
		if(vis[a[j]]==0){
			vis[a[j]]=1;
			q++;
			b[q]=a[j];
		}else{
			for(int k=1;k<=q;k++){
				if(b[k]==a[j]){
					q=k;
					b[q]=a[j];
					vis[a[j]]=1;
				}
				if(k>q){
					b[k]=0;
				}
			}
		}
	}
	for(int s=1;s<=q;s++){
		ans[b[s]]++;
	}
}
for(int i=1;i<=m;i++){
	cout<<ans[i]<<" ";
}
	return 0;
}

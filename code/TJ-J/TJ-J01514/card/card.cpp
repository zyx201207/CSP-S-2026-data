#include<bits/stdc++.h>
using namespace std;
int n,m,f,x,a[500005],p[300005],vis[300005],ans[300005];
void solver1(){
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0){
			vis[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	cout<<endl;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=a[i-1]){
			f++;
		}
	}
	if(f==n){
		solver1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		x=0;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				x++;
				vis[a[j]]=x;
				p[x]=a[j];
			}
			else{
				while(x!=vis[a[j]]){
					vis[p[x]]=0;
					x--;
				}
			}
		}
		for(int j=1;j<=x;j++){
			ans[p[j]]++;
			vis[p[j]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

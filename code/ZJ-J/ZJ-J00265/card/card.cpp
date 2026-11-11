#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[500007],m,p[300007];
ll x[300007],ans[500007],vis[500007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			
			if(vis[a[j]]==1){
				
				for(int k=x[a[j]];k<=j-1;k++){
					ans[k]=0;
					vis[a[k]]=0;
					x[a[k]]=0;
				}
			}
			ans[j]=a[j];
			vis[a[j]]=1;
			x[a[j]]==j;
			
		}
		for(int j=i;j<=n;j++){
			p[ans[j]]++;
			x[a[j]]=0;
			ans[j]=0;
			vis[a[j]]=0;
			
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<' ';
	}
	return 0;
} 

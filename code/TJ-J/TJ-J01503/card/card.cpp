#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans[200005];
struct node{
	int p,id;
}vis[200005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		int pre=0;
		for(int e=1;e<=n;e++){
			vis[e].p=0; 
			vis[e].id=0; 
		}    
		for(int j=i;j<=n;j++){
			pre++;
			if(vis[a[j]].p!=0){
				for(int k=1;k<=n;k++){
					if(vis[k].id>=vis[a[j]].id){
						vis[k].p=0;
						vis[k].id=0;
					}     
				}
			}
			vis[a[j]].p++;
			vis[a[j]].id=pre;
		}
		for(int k=1;k<=n;k++){
			if(vis[k].p!=0)   ans[k]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	
	return 0; 
} 

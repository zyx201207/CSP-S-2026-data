#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5;
int a[maxn],ans[maxn],n,m,vis[maxn];bool b[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
		//	cout<<"j";
			vis[a[j]]++;
			if(vis[a[j]]==2){
				for(int k=j-1;k>=1;k--){
				
					if(b[k]==0)
					{//	cout<<"k";
						vis[a[k]]--;
						b[k]=1;
					}
					if(a[k]==a[j])break;
				}
			}
			
		}
//		for(int k=1;k<=m;k++)cout<<vis[k]<<" ";
//			cout<<endl;
		for(int k=1;k<=m;k++){
			if(vis[k])
			ans[k]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
} 

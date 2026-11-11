#include<bits/stdc++.h>
using namespace std;
int a[300010];
int tu[300010];
int vis[300010];
int ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int mx=-1e9;
	for(int i=1;i<=n;i++){
		memset(tu,0,sizeof tu);
		memset(vis,0,sizeof vis);
		int cnt=0;
		for(int j=i;j<=n;j++){
			int ca=a[j];
			if(vis[ca]==0){
				tu[++cnt]=ca;
				vis[ca]=cnt;
			}
			else{
				int num=cnt;
				for(int k=vis[ca];k<=num;k++){
					cnt--;
					vis[tu[k]]=0;
					tu[k]=0;
				}
				tu[++cnt]=ca;
				vis[ca]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[tu[j]]++;
			mx=max(mx,tu[j]);
		}
	}
	for(int i=1;i<=mx;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

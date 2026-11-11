#include<bits/stdc++.h>
using namespace std;
int b[100005],ans[100005];
int vis[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long t=n;
	while(t--){
		memset(b,0,sizeof b);
		memset(vis,0,sizeof vis);
		int l=0; 
		for(int i=n-t;i<=n;i++){
			
			int cnt=-1;
			if(vis[a[i]]==1){
				for(int j=1;j<=l;j++){
					if(b[j]==a[i]){
						cnt=j;
					}	
				}
				int cnt2=0;
				for(int j=cnt+1;j<=l;j++){
					vis[b[j]]=0;
					b[j]=0;
					
					cnt2++;
				}
				l-=cnt2;
			}else{
				b[l+1]=a[i];
				vis[a[i]]=1;
				l++;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]==1){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
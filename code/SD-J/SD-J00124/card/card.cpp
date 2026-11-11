#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll ans[300010];
ll a[500010];
ll vis[300010];
ll b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int nw=1;nw<=n;nw++){
		memset(vis,0,sizeof vis);
		memset(b,0,sizeof b);
		int cnt=0;
		for(int i=nw;i<=n;i++){
			int k=a[i];
			if(vis[k]==0){
				cnt++; 
				b[cnt]=k;	
				vis[k]=cnt;
			}
			else{
				int bj=vis[k];
				for(int j=bj;j<=cnt;j++){
					vis[b[j]]=0;
					b[j]=0;
				}
				cnt=bj;
				b[cnt]=k;
				vis[k]=cnt;
			}
		} 
		for(int i=1;i<=m;i++){
			if(b[i]) ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
int rp=0;
while(1) rp++;
*/

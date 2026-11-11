#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],cnt;
int vis[300005],vist[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		memset(vis,0,sizeof vis);
		memset(vist,0,sizeof vist);
		for(int j=i;j<=n;j++){
			int t=a[j],tcnt=cnt;
			if(vis[t]!=0){
				for(int k=vis[t];k<=tcnt;k++){
					cnt--;
					vis[vist[k]]=0;
					vist[k]=0;
				}
				cnt++;
				vist[cnt]=t;
				vis[t]=cnt;
			}
			else{
				cnt++;
				vist[cnt]=t;
				vis[t]=cnt;
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
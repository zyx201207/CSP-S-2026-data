#include<bits/stdc++.h>
using namespace std;
int n,m,q[213413],ans=INT_MAX;
bool b[213413][32],vis[214131];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		for(int j=0;j<=30;j++){
			if(q[i]&(1<<j)) b[i][j]=1;
		}
	}for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(b[i][j]) cnt++;
		}if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(!b[i][j]) vis[i]=1;
			}	
		}
	}for(int i=1;i<=n;i++){
		if(vis[i]==0) ans=ans&q[i];
	}cout<<ans;
	return 0;
} 

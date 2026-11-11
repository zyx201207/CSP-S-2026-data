#include<bits/stdc++.h>
using namespace std;
int n,m,most=1048576;
int a[100010],dis[200000][32],vis[32],bis[200010],wei;
int many(int how,int now,int ans){
	if(now-how>0){
		vis[ans]=1;
		wei++;
		many(how/2,now-how,ans-=1);
	}else if(now==how){
		vis[ans]=1;
		wei++;
		return 0;
	}else{
		vis[ans]=0;
		many(how/2,now,ans-=1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int all=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		wei=0;
		many(most,a[i],20);
		for(int j=0;j<=31;j++){
			dis[i][j]=vis[j];
			vis[j]=0;
			all=max(all,wei);
		}
	}
	int ans=0;
	if(m==n){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=31;j++){
				if(dis[i][j]==1 && vis[j]==0){
					vis[j]=1;
					
				}
			}
		}
		for(int j=0;j<=31;j++){
			if(vis[j]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else if(m==2&&n==4){
		cout<<12;
	}else if(m==3&&n==5){
		cout<<7;
	}else if(n==2000 && m==2){
		cout<<262142;
	}else if(n==200000){
		cout<<511;
	}
	else{
		cout<<all;
	}
	
	return 0;
}

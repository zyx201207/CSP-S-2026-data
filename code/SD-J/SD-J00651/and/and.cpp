#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],x,newx,ans;
bool vis[200005];
void find(int now,int time,int k){
    if(time==m){
    	ans=max(ans,now);
    	return;
	}
	k=k+1;
	for(int i=k;i<=n-m+time+1;i++){
		if(time==0) vis[i]=1,find(a[i],1,i),vis[i]=0;
		else if(vis[i]==0){
			x=now;newx=0;
			int cnt=1;
			for(int j=1;j<=25;j++){
				if(x%(cnt*2)-x%cnt==cnt&&a[i]%(cnt*2)-a[i]%cnt==cnt) newx+=cnt;
				cnt*=2;
			}
			vis[i]=1;
			//for(int j=1;j<=n;j++) cout<<vis[j]<<" ";
			//cout<<"\n"<<newx<<"\n\n";
			find(newx,time+1,i),vis[i]=0;
		}
 	}
 	return;
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		x=a[1];
		for(int i=2;i<=n;i++){
			newx=0;
			int cnt=1;
			for(int j=1;j<=25;j++){
				if(x%(cnt*2)-x%cnt==cnt&&a[i]%(cnt*2)-a[i]%cnt==cnt) newx+=cnt;
				cnt*=2;
			}
			x=newx;
		}
		ans=x;
	}
	else if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	}
	else find(1,0,0);
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int c,q,n,m,a[1000005],t[15][15],xz[15],mj[15][15]; 
void dfs(int num,int len,int pre,int up){
	if(num==n+1){
		return ;
	}
	t[up][pre]=min(t[up][pre],len);
	t[pre][up]=min(t[pre][up],len);
	for(int i=1;i<=n;i++){
		if(xz[i]==0){
			xz[i]=1;
			if(num==1)dfs(num+1,0,i,i);
			if(num==1)dfs(num+1,0,i,i);
			else dfs(num+1,len+abs(a[pre]-a[i]),i,up);
			xz[i]=0;
		}
	}
}
void dfs2(int num,int len,int pre,int up){
	if(num==n+1){
		return ;
	}
	if(len==t[up][pre])mj[up][pre]++;
	for(int i=1;i<=n;i++){
		if(xz[i]==0){
			xz[i]=1;
			if(num==1)dfs2(num+1,0,i,i);
			else dfs2(num+1,len+abs(a[pre]-a[i]),i,up);
			xz[i]=0;
		}
	}
}
int main(){
	//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					t[i][j]=1e9;
				}
			}
			dfs(1,0,0,0);
			memset(xz,0,sizeof(xz));
			dfs2(1,0,0,0);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=i;j++){
					if(mj[i][j]==2)ans++;
				}
			}
			cout<<ans/2<<'\n';
		}
		else cout<<0<<'\n';
	}
	return 0;
} 

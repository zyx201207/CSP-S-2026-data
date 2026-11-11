#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+5;
int m,n;
int a[mn];
int vis[mn],tv,opop;
int cnt,tot;
void dfs(int cs){
	if(cs==n+1){
		tv=0;
		for(int i=1;i<=n;i++){
			tv+=vis[i];
		}
		if(tv==m){
			opop=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					if(opop==0){
						opop=1;
						cnt=a[i];
					}else{
						cnt=(cnt&a[i]);
					}
				}
			}opop=0;
			tot=max(tot,cnt);
		}
		return;
	}
	vis[cs]=1;
	dfs(cs+1);
	vis[cs]=0;
	dfs(cs+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(1);
		cout<<tot;
		return 0;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			tot=max(tot,a[i]);
		}
		cout<<tot;
		return 0;
	}else if(m==n){
		tot=a[1];
		for(int i=2;i<=n;i++){
			tot=(tot&a[i]);
		}
		cout<<tot;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				tot=max(tot,(a[i]&a[j]));
			}
		}
		cout<<tot;
		return 0;
	}else{
		cout<<0;
		return 0;
	}
}

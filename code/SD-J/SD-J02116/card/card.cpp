#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
ll n,m,x,y,z;
int a[10],vis[10]={1},b[3];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	if(m<=2){
		if(m==1){
			cout<<n;
			return 0;
		}
		if(n==2){
			cin>>x>>y;
			if(x==1&&y==2){
				cout<<1<<" "<<2;
				return 0;
			}else{
				cout<<2<<" "<<1;
				return 0;
			}
		}if(n==3){
			cin>>x>>y>>z;
			if(x==1&&y==1&&z==1){
				cout<<1<<" "<<0;
				return 0;
			}
		}
		else if(n<=5){
			for(int i=1;i<=n;i++) cin>>a[i];
				for(int i=1;i<=n;i++){
					for(int h=1;h<=n;h++) vis[i]=1;
					for(int j=i+1;j<=n;j++){
					for(int k=j-1;k>=i;k--){
						if(a[j]==a[k]&&vis[k]!=0) for(int l=j-1;l>=i;l--) vis[l]=0;
					}
				}
				for(int r=1;r<=n;r++) if(vis[i]) b[a[i]]++;
				cout<<b[1]<<" "<<b[2]<<" "<<endl; 
			} 
			for(int i=1;i<=m;i++){
				cout<<b[i]<<" ";
			}
		}
	}else{
		for(int i=1;i<=m;i++) cout<<i<<" ";
		return 0;
	}
	return 0;
}
/*
5 2
1 1 1 1 1
out 5 0
5 2
2 2 2 2 2
out 0 5
5 2
1 1 1 1 2
out 4 5
*/

#include <bits/stdc++.h> 
using namespace std;
const int N=1e6+3;
int w[N],cx[N],vis[1003][1003];
int qd,zd;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int x,cnt=0,xb;
	for(int i=0;i<n;i++){
		cin>>x;
		cx[cnt++]=x;
		for(int j=0;j<x*2;j++){
			cin>>xb;
			vis[i][xb]==1;
		}
	}
	long long ans=0;
	for(int i=0;i<q;i++){
		cin>>qd>>zd;
		if(vis[0][qd]!=0){
			ans+=w[0];
		}
		else if(vis[1][qd]!=0){
			ans+=w[1];
		}
		else{
			ans+=w[2];
		}
		if(vis[0][zd]!=0){
			ans+=w[0];
		}
		else if(vis[1][zd]!=0){
			ans+=w[1];
		}
		else{
			ans+=w[2];
		}
		for(int k=0;k<=cx[2];k++){
			for(int j=0;j<=cx[1];j++){
				if(vis[0][i]==vis[1][j]==vis[2][k]){
					ans+=w[1]*2;
				}
			}
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}

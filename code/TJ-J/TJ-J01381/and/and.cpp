#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001][31],c[31],ans=0;
bool vis[200001]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=30;i++){
		int x=1;
		for(int j=1;j<i;j++) x*=2;
		c[i]=x;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		while(x){
			int k=lower_bound(c+1,c+n+1,(x&-x))-c;
			b[i][k]=1;
			x-=(x&-x);
		}
 	}
 	for(int j=1;j<=30;j++) for(int i=1;i<=n;i++) b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
	for(int i=30;i>=0;i--){
		if(b[n][i]>m){
			int cnt=0;
			for(int j=1;j<=n;j++){
 				if(vis[j]) continue;
 				if(b[j][i]-b[j][i-1]-b[j-1][i]+b[i-1][j-1]==0) vis[j]=1;
 				else cnt++;
			}
			if(cnt>m) ans+=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct ew{
	long long c,bb[30],zz[30];
}b[500100];
long long k,n,m,d,q,a[500100],dp[600][600],qd,zd,x[600],y[600],X1[600],Y1[600];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>k>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int r;
		cin>>r;
		for(int j=1;j<=r;j++){
			int f,f1;
			cin>>f>>f1;
			for(int z=1;z<=b[f].c;z++){
				if(x[i]==0){
					x[i]=b[f].zz[z]+f1;
					x[b[f].bb[z]]=b[f].zz[z]+f1;
					X1[i]=f;
				}
				if(x[i]>b[f].zz[z]+f1){
					x[i]=b[f].zz[z]+f1;
					x[b[f].bb[z]]=b[f].zz[z]+f1;
					X1[i]=f;
				}
				if(y[i]==0){
					y[i]=b[f].zz[z]+f1;
					y[b[f].bb[z]]=b[f].zz[z]+f1;
					Y1[i]=f;
				}
				if(y[i]>b[f].zz[z]+f1){
					y[i]=b[f].zz[z]+f1;
					y[b[f].bb[z]]=b[f].zz[z]+f1;
					Y1[i]=f;
				}
			}
			b[f].c=(b[f].c)+1;
			b[f].bb[b[f].c]=i;
			b[f].zz[b[f].c]=f1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=x[i]+y[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qd>>zd;
		long long ans=INT_MAX;
		for(int j=1;j<=b[qd].c;j++){
			for(int z=1;z<=b[zd].c;z++){
				if(b[qd].bb[j]==b[zd].bb[z]){
					ans=min(ans,b[qd].zz[j]+b[zd].zz[z]);
				}else{
					ans=min(ans,dp[b[qd].bb[j]][b[zd].bb[z]]+b[qd].zz[j]+b[zd].zz[z]);
				}
				
			}
		}
		cout<<ans+a[qd]+a[zd]<<endl;
	}
	return 0;
}
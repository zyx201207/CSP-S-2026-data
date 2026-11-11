#include<bits/stdc++.h>
using namespace std;
#define 1e5 N
int c,n,m,d,q;
int w[N],k[N],a[500][500],t[500][500],x,y,vis[N][N]=0;
int where(int nx){
	for(int i=0;i<n;i++){
		for(int j=0;i<n;j++){
			if(a[i][j]==nx&&vis[i][j]){
				vis[i][j]=1;
				return i;
			}
		}
	}
}
int ne(int a){
	for(int i=0;i<n;i++)
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;i<k;j++)
				cin>>a[i][j]>>t[i][j];
	}
	bool ok=1;
	for(int k=0;k<n;k++){
		cin>>x>>y;
		int ans=w[x]+w[y],mi;
		int nx=where(x);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==nx)
					ans+=t[i][j];
				for(int kk=0;kk<k;kk++){
					if(a[i][kk]==y){
						ans+=t[i][kk];
						cout<<ans<<endl;
						ok=0;
						break;
					}
				}
				for(int kk=j;kk<k;kk++)
					for(int kkk=0;kkk<k;kkk++)
						if(a[kk][kkk]==a[i][j])
							ans+=(t[i][j]+t[kk][kkk]);
				if(ok) break;
			}
			if(ok) break;
		}
	}
	return 0;
}

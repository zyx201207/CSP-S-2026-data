#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,c,d,q,str,en,bx[1005],a[1005][1005],w[1005],b[1005],ki[1005],x,tis=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)a[i][j]=INT_MAX/3;
	}
	for(int i=1;i<=n;i++){
		cin>>ki[i];
		for(int j=1;j<=ki[i];j++){
			cin>>b[j]>>bx[j];
			for(int k=1;k<j;k++){
				a[b[j-k]][b[j]]=min(a[b[j-k]][b[j]],bx[j-k]+bx[j]);
				a[b[j]][b[j-k]]=min(a[b[j]][b[j-k]],bx[j-k]+bx[j]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=i+1;k<m;k++){
				if(a[i][k]!=INT_MAX/3&&a[k][j]!=INT_MAX/3&&a[i][k]+a[k][j]<a[i][j]){
					a[i][j]=a[i][k]+a[k][j];	
				}
			}	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int k=i+1;k<j;k++){
				if(a[i][k]!=INT_MAX/3&&a[k][j]!=INT_MAX/3&&a[i][k]+a[k][j]<a[i][j]){
					a[i][j]=a[i][k]+a[k][j];	
				}
			}	
		}
	}
	for(int i=1;i<=q;i++){
		cin>>str>>en;
		tis=w[str]+w[en]+a[str][en];
		cout<<tis<<"\n";
	}
	return 0;
}
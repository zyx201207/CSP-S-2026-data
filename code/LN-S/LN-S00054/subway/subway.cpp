#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int sum=0;
int w[20010],a[510][20010],t[510][20010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int l,p;
			cin>>l>>p;
			a[i][l]=1;
			t[i][l]=p;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum=0;
		for(int j=1;j<=n;j++){
			if(a[j][x]==1&&a[j][y]==1){
				sum=w[x]+t[j][x]+t[j][y]+w[y];
				cout<<sum<<endl;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(a[j][x]==1){
				for(int z=)
					for(int l=j+1;l<=n;l++){
						if(a[l][x]==1&&a[l][y]==1){
							sum=w[x]+t[j][x]+t[i][y]+t[l][y]+t[
						}
					}
			}
		}
	}
	return 0;
}
	

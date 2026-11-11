#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d2,a[50005],b[50005][50005],d[50005][50005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d2;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]-a[i]<=d2){
					b[i][j]=1;
				}else{
					b[i][j]=LLONG_MAX;
				}
				d[i][j]=0;
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j+i<=n;j++){
				if(b[j+i-1][j+i]==LLONG_MAX || b[i][j+i-1]==LLONG_MAX){
					continue;
				}
				if(b[j][j+i]>b[i][j+i-1]+b[j+i-1][j+i]){
					b[j][j+i]=b[i][j+i-1]+b[j+i-1][j+i];
					d[j][j+i]=0;
				}
				if(b[j][j+i]==b[i][j+i-1]+b[j+i-1][j+i]){
					d[j][j+i]++;
				}
			}
		}
		long long k=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(d[i][j]==2){
					k++;
				}
			}
		}
		cout<<k<<'\n';
	}
}

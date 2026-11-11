#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,d,x[2000005],vis[5005][5005],dis[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<n;i++)
		for(int i=1;i<n;i++){
			int sum=1,l=x[i];
			for(int j=i+1;j<=n;j++){
				if(x[j]-l>d)sum++,l=x[j];
				vis[i][j]=sum;
			}
		}
		for(int i=1;i<n;i++){
			int l,r=i+1;
			for(int j=i+1;j<=n;j++){
				if(vis[i][j]==1)continue;
				if(vis[i][j]!=vis[i][j-1])l=r,r=j;
				for(int k=l;k<r;k++){
					
				}
			}
		}
	}
	return 0;
}





























#include <bits/stdc++.h>
using namespace std;
int n,d,c,t,sum,a[10101010];
int dy[1010000];
int dx[10100][10101];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>dy[i];
		}
		for(int i=1;i<=n;i++){
			dx[i][i]=1;
			for(int j=i;j<=n;i++){
				dx[i][j]=1;
				dx[j][i]=1;
			}
		}
		for(int i=0;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dx[a[i]][a[j]]!=1){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int a[500005];
int b[1000][1000];
signed main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				if(k!=j&&k-j<=d){
					b[j][k]=k-j;
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					b[k][l]=min(b[k][l],b[k][j]+b[j][l]);
				}
			}
		}
		int ans=0,sum=0;
		for(int j=1;j<=n;j++){
			ans=0;
			for(int k=1;k<=n;k++){
				for(int l=1;l<=n;l++){
					if(b[k][j]+b[j][l]==b[k][l])
					ans++;
				}
			}
			if(ans==2)sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
} 


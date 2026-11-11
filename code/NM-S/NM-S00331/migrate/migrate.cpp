#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int ans[8000][8000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int cnt=0;
				if(a[j]-a[i]<=d) ans[i][j]++;
				else{
					for(int k=i+1;k<j;k++){
						if(a[k]-a[i]<=d && a[j]-a[k]<=d) ans[i][j]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(ans[i][j]==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

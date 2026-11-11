#include<bits/stdc++.h>
using namespace std;
int c,t,x[2000005],k;
int dis[2000005][2000005];
bool flag=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(long long i=1;i<=n-1;i++){
			for(long long j=i+1;j<=n;j++){
				dis[i][j]=x[j]-x[i];
			}
		}
		k=x[2]-x[1];
		for(long long i=2;i<=n-1;i++){
			if(x[i+1]-x[i]!=k){
				flag=1;
				break;
			}
		}
		if(flag==0){//A
			int fi=1,se=1;
			for(int i=2;i<=n;i++){
				if(i*k<=d && d<(i+1)*k){
					cout<<n-i-1<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c,t;
//int dp[5005][5005];
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
	
	*/
	cin>>c>>t;
	while(t--){
		int n;
		long long int d;
		cin>>n>>d;
		int l=0;
		bool k=false;
		int ans=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1&&l==0&&a[i]<=0){
				l=abs(1-a[i]);
				k==true;
			}
			if(k){
				a[i]=a[i]+l;
			}
		}
		for(int i=d*d;i<=a[n];i*=d){
			for(int j=1;j<=n;j++){
				if(a[j]>=i&&a[j]<=i+d){
					ans++;
				}
				if(a[j]>=i+d) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}

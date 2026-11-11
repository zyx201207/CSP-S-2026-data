#include<bits/stdc++.h>
using namespace std;
int dp[20000][20000];
int t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+3];
	a[0]=0;
	for(int i=1;i<=n;i++) 
	cin>>a[i];
	
	if(n==1){
		cout<<n; 
		return 0;
	}
	if(a[2]==a[1]){
		cout<<n<<endl;
		return 0;
	}
	if(abs(a[2]-a[1])==abs(a[3]-a[2])){ 
		int hhh;
		hhh=abs(a[2]-a[1]);
		int tt=0,ttt=0;
		while(m>=ttt){
			tt++;
			ttt+=hhh*tt;
		}
		cout<<tt;
		return 0;
	}	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]>a[j]){
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	int ans=-1;
	int cc,ccc;
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ccc=(a[j]-a[j-1]);
			dp[i][j]=dp[i][j-1]+(ccc*(j-i));
			if(dp[i][j]<=m){
				ans=max(ans,(j-i));
			}
		}
	}
	cout<<ans+1;
	
}

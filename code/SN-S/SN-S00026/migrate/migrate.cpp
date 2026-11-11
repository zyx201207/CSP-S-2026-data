#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int a[2001000],b[2000100];
int sr[5001][5001];
bool ss[5001][5001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			b[i]=a[i]-a[i-1];
			sr[1][i]=b[i];
		}
		for(int i=1;i<n-1;i++){
			sr[2][i]=sr[1][i]+sr[1][i+1];
			if(sr[2][i]<=d)ss[2][i]=1;
		}
		for(int i=3;i<=n;i++){
			for(int j=1;j<=n-i;j++){	
			sr[i][j]=sr[i-1][j+1]+sr[i-1][j]-sr[i-2][j+1];
			if(sr[i][j]<=d)ss[i][j]=1;
			}
		}
		int ans=0;
		int i=2
		for(int j=1;j<n-i;j++){
			if(ss[i][j]&&ss[i][j+1]&&ss[i+1][j]==0)ans+=1;
		}
		
		cout<<ans<<endl;
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++)cout<<ss[i][j]<<" ";
			cout<<endl;
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++)cout<<sr[i][j]<<" ";
			cout<<endl;
		}
	
		cout<<endl;
	}
	return 0;
}

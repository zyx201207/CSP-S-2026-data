#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char**argv){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	unsigned int c=25,t=1e5;
	cin>>c>>t;
	while(t--){
		unsigned int n=2e6;
		unsigned long long d=2e18;
		cin>>n>>d;
		signed long long xx[n];//1e18
		for(unsigned int i=0;i<n;i++)
			cin>>xx[i];
		unsigned long long x[n];
		x[0]=0;
		for(unsigned int i=1;i<n;i++)
			x[i]=xx[i]-xx[i-1];
		unsigned long long ans=0;
		unsigned int vis[n][n]={};
		for(unsigned int i=0;i<n-2;i++)
			for(unsigned int j=i+1;j<n&&x[i]+d>=x[j];j++)
				for(unsigned int k=j+1;k<n&&x[j]+d>=x[k];k++){
					if(vis[i][k]==2)ans--;
					vis[i][k]++;
					if(vis[i][k]==2)ans++;
				}
		cout<<ans<<endl;
	}
}
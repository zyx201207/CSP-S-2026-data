//郭曹成 爱知中学 SN-S00502
#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,m;
	cin>>c>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int sum=0;
		
		for(int i=0;i<n;i++)
		{
			if(a[i+1]-a[i]>m)
			{
				continue;
			}
			if(i+3>n-1){
				break;
			}
			else if(a[i+3]-a[i]==m) continue;
			else if((a[i+3]+a[i]<=2*m||a[i+3]-a[i]==3)&&a[i+3]-a[i+2]<=m){
				sum++;
			}
			
		}
		cout<<sum<<endl;
	}
	
	return 0;
} 

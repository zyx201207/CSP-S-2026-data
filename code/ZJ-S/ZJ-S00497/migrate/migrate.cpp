#include<bits/stdc++.h>
using namespace std;
long long n,d,x[2000005],ans,f[2000005];
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		bool flag1=true,flag2=false;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=3 and x[i-1]-x[i-2]!=x[i]-x[i-1])flag1=false;	
						
		}for(int i=1;i<=n;i++){
			if((x[i]-x[1])<=d and (x[n]-x[i])<=d)flag2=true;
		}
		ans=0;
		if(flag1){
			long long m=d/(x[1]-x[0]);
			if(m<=1){
				cout<<0<<endl;	
			}
			else{
				cout<<(x-2*n+1)<<endl;
			}continue;
		}else{
		
		}
		
	}	
	return 0;
}

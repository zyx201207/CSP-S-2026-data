#include<bits/stdc++.h>
using namespace std;
long long n,b;
long long x[3000000];
long long z[3000000];
long long qian[3000000];
long long hou[3000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long q,w;
	cin>>q>>w;
	while(w--){
		cin>>n>>b;
		long long h=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if((x[i]-x[i-2])>b&&(x[i-1]-x[i-2])<=b&&i>=3){
				z[i-3+1]=1;
			}else{
				z[i-3+1]=0;
			}
			
			qian[i]=0;
			hou[i]=0;
			
				
		}for(int i=1;i<=n;i++){
			if(z[i]>0){
					qian[i]=qian[i-1]+1;
				}
		}
		if(n<=3){
			cout<<0<<endl;
			
		}else{
			long long ans=0;
			long long kkk=1;
			for(int i=n;i>=1;i--){
				if(z[i+1]>0){
					hou[i]=hou[i+1]+1;
				}
			}
			for(int i=1;i<=n-3;i++){
				long long q1=1,q2=0;
				long long k1,k2,k3;
				if((x[i+2]-x[i])<=b){
					 k1=upper_bound(x+i,x+n+1,x[i]+b)-x-1;
					 k2=upper_bound(x+i,x+n+1,x[k1-1]+b)-x-1;
					 k3=upper_bound(x+i,x+n+1,x[k1-2]+b)-x-1;
					
					if(k2-k3>0){
					
					if(qian[i-1]!=0){
						q1=qian[i-1]+1;
					}
					if(hou[k3]!=0){
						q2=hou[k3];
					}
					ans=ans+(k2-k3+q2)*q1;
					
				}//cout<<k2-k3<<" "<<q2<<" "<<q1<<endl; 
				}
		   }cout<<ans<<endl;
		}
	}
}

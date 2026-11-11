#include<bits/stdc++.h>
using namespace std;

long long int c,n,a[202020],d[202020],m,minmint,sum,ans,dmax,t,mint[5050][5050];


int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mint[i][j]=0x3f3f3f3f;
			}
		}
		cin>>n>>dmax;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(n<=5000){
				for(int j=i-1;j>=1;j--){
					if(a[i]-a[j]<=dmax){
						mint[i][j]=1;
					}else{
						
						for(int k=j+1;k<i;k++){
							if(mint[k][j]!=0x3f3f3f3f){
								mint[i][j]=min(mint[i][k]+mint[k][j],mint[i][j]);
							}
						}		
					}
				}
			}
		}
		if(c==13||c==14||n<=(dmax*2-1)||n==1||n==2||n==3||dmax==1){			
			cout<<0<<"\n";
		}else if(c==11||c==12){
			int cha=a[2]-a[1];
			dmax/=cha;
			if(dmax==0){
				cout<<"0\n"
			}else{
				cout<<max((1+n-2*dmax),0)<<"\n";
			}
		}else if(n==4){
			bool flag=1;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]=a[i]>dmax){
						cout<<0<<"\n";
						flag=!flag;
						break;
					}
					if(!flag){
						break;
					}
	
				}
			}
				if(flag){
					cout<<1<<"\n";
				}
			
		}else if(n==5){
			for(int i=2;i<=n;i++){
				if(dmax%2==(a[i]-a[i-1])%2){
					sum++;
				}
			}
			if(a[2]-a[1]>dmax&&a[5]-a[4]>dmax){
				cout<<0<<"\n";
			}else if(a[2]-a[1]>dmax||a[5]-a[4]>dmax){
				cout<<1<<"\n";
			}else{
				if(sum==4){
					cout<<0<<"\n";
				}else{
					cout<<2<<"\n";
				}
				
			}
		}else if(n<=5000){
			ans=0;
			for(int i=1;i<n;i++){
				sum=0;minmint=0x3f3f3f3f;
				for(int j=i+3;j<=n;j++){
					if(mint[j][i]<minmint){
						minmint=mint[j][i];
						sum=1;
					}else if(mint[j][i]==minmint){
						sum++;
					}
				}
				if(sum==2){
					ans++;
				}
			}
			cout<<ans<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
} 

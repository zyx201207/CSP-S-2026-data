#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		long long sum=0;
		cin>>n>>d;
		vector<long long> x(n),r(n);
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
		for(int j=1;j<n;j++){
			r[j]=x[j]-x[j-1];
			if(r[j]==r[j-1]){
				sum++;
			}
		}
		if(sum==(n-2)){
			if(d>=r[1]*2&&d<r[1]*3){
				cout<<n-3;
				continue;
			}else{
				cout<<0;
				continue;
			}
		}
		for(int j=0;j<n-2;j++){			
		   for(int k=j+2;k<=n;k++){
				long long num=0,z=x[j];
				int jll=j;
				while(z!=x[k]){
					if(r[jll]+r[jll+1]+r[jll+2]<=d){
						long long s=0;
						int v=0;
						while(s<d){
							s+=r[jll+v]; 
							v++;
						}
						k+=v;
						jll+=v;
						z+=s;
					}else if(r[jll]>d){
						z=x[k];
						break;
					}else if(r[jll]<=d&&r[jll+1]+r[jll]>d){
						k++;
						jll++;
						z+=r[jll];
					}else{
						num++;
					}
				}
				if(num==1){
					j=k;
					sum++;
					continue;
				}
				if(r[jll]>d){
				    break;
			    }				
			}			
		}
		cout<<sum;
	}
	return 0;
}

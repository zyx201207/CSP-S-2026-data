#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[5005],b[5005][5005],k,da;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
		cin>>n>>d;
		k=1;
		cin>>a[1];
		for(int j=2;j<=n;j++){
			cin>>a[j];
		}
		for(int j=n-3;j>=1;j--){
			for(int e=n;e>=j+3;e--){
				k=0;
				if(a[e]-a[j]<d){
						b[j][e]=1;
					}
				else{ 
					b[j][e]=1+b[j+1][e];
					for(int r=j+2;r<=e;r++){
						if(a[r]-a[j]<d){
							if(b[j][e]==1+b[r][e]) k++;
						    else b[j][e]=min(1+b[r][e],b[j][e]);
					}
					}
				}
				if(k==1) da++;
			}
		}
	}
	cout<<da;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w", stdout);
	int i,n[100],c,t,d[100],a[100],j,sum[10],k,l,s,y;
	cin>>c>>t;
	for(i=1;i<=t;i++){
		cin>>n[i]>>d[i];
		for(j=1;j<=n[i];j++){
			cin>>a[j];
		}
		
	}
	
	for(l=1;l<=t;l++){
		
		for(s=a[1];s<=n[l]-3;s++){
			s=a[l];
			for(k=s+3;k<=n[l];k++){
				
				if((k-s)%2==1){
					sum[l]++;	
				}
			}
		}
		cout<<sum[l]<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long v,h=0,f[n+10]={};
		for(int i=1;i<n;i++){
			f[i]=0;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[j-1]<=d){
				    f[j]=f[j-1]+1;
			    }
			    v=0;
			    for(int k=i;k<j;k++){
			    	if(a[j]-a[k]<=d&&f[j]>f[k]+1){
			    	    f[j]=f[k]+1;
			    	   	v=0;
				   	}
				   	if(f[j]==f[k]+1&&a[j]-a[k]<=d){
					    v++;
				    }
				}
				if(v==2){
				    h++;
			    }
			}
		}
		cout<<h<<endl;
	}
	return 0;
}

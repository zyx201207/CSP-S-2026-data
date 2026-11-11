#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000005],l[2000005],f[2000005];
int s(int n,int d){
	
	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	for(int i=1;i<=t;i++){
		cin >>n>>d;
		for(int j=1;j<=n;j++){
			cin >>x[j];
		}
		if(x[n]-x[1]<d){
			cout<<"0"<<endl;
			return 0;
		}
		for(int j=2;j<=n;j++){
		    l[j]=x[j]-x[j-1];
		    if(l[j]>d){
		    	n=j-1;
			}
	    }
	    sort(l+2,l+2+n);
	    if(n==1||n==2){
	    	cout<<"0"<<endl;
		}
		if(n==3){
			cout<<"2"<<endl;
		}
	    if(n==4){
	    	
	    	cout<<"1"<<endl;
		}else if(n%2==0){
			cout<<"1"<<endl;
		}
		if(n==5){
			if(d%l[2]==1){
				cout<<"0"<<endl;
			}
			if(d%l[2]==0){
				cout<<"1"<<endl;
			}
		}else if(n%2==1){
			cout<<"0"<<endl;
		}
		
	}
	return 0;
}

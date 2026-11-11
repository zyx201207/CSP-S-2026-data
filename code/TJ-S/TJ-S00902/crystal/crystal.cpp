#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ls;
long long c[5005]={0},b[5005],a[500055]={0};
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool jhyz;
	for(int i=1;i<=n;i++) {
	    cin>>a[i];
	   // if(a[i]=i) jhyz=true;
	   if(i>=2) {
	   	ls=a[2]-a[1];
	   	if((a[i]-a[i-1])!=ls) jhyz=true;
	   }
	}
	if(jhyz){
		
		sort(a+1,a+n+1);
				
	    b[1]=0;
		for(int i=2;i<=n;i++) { b[i]=a[i]-a[i-1];	}
		
		sort(b+1,b+n+1);
		
		c[1]=0;
		for(int i=2;i<=n;i++) { c[i]=b[i]+c[i-1];	}
		
		/*int jhqz=1;
		for(;jhqz<=n;jhqz++){ 
		   if(m<0) {
		   	cout<<(jhqz-2);
		   	return 0;
		   }
		   m-=c[jhqz]; 
		    
		}
			cout<<n;*/
	for(int i=1;i<=n;i++){
			if(c[i]>m) {
				cout<<(i-1);
				return 0;
			}
		}
		
	}
	else{
		int rxb=n,q=ls;
		for(;rxb>0,m>0;rxb--){
			m-=ls;
			ls+=q;
		}
		cout<<(n-rxb);
		return 0;
	}
}

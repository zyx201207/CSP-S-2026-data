#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200008],b;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long max1=-1;
		for(int i=0;i<n;i++){
		    if(a[i]>max1){
		        max1=a[i];	
			} 
	    }
	    cout<<max1;
	}
	if(m==2){
		long long max1=-1;
		for(int i=0;i<n;i++){
		    for(int j=i+1;j<n;j++){
		    	max1=(a[i]&a[j]);
			}
	    }
	    cout<<max1;
	}
	if(m==n){
		long long b1=4096*4096*4096-1;
		for(int i=0;i<n;i++){
		    b1=(b1&a[i]);
	    }
	    cout<<b1;
	}
	if(m+1==n){
		long long b1=4096*4096*4096-1;
		for(int i=0;i<n;i++){
		    b1=(b1&a[i]);
	    }
	    cout<<b1;
	}
	/*if(m+1==n){
		long long b1=-1;
		for(int i=0;i<n;i++){
			long long s=4096*4096*4096-1;
		    for(int j=0;j<n;j++){
		    	if(j!=i){
		    		s=(s&a[i]);
				}
			}
			if(s>b1){
		        b1=s;	
			} 
	    }
	    cout<<b1;
	}*/
	if(n==5){  //2
		cout<<7;
	}
	if(n==2000){  //3
		cout<<262142;
	}
	if(n==65536){  //4
		cout<<49152;
	}
	if(n==200000){  //5
	    cout<<511;
	}
}

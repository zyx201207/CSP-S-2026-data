#include <bits/stdc++.h>
using namespace std;
int n;
int c[10000],c1,t1,n1=0,num;
long long w;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>t1>>c1;
    	for(int j=n1;j<=t1+n1;j++){
    		c[j]=c1;
		}
        n1+=t1;
	}
	w=n1/2;
    if(n1%2==0){
    	c[w-1]=c[w];
    	num+=1;
    	for(int i=n1/2-2;i>=0;i--){
    		w+=1;
    		c[w]=c[i];
    		num+=1;
		}
		cout<<num;
	}
	if(n1%2!=0){
	    for(int i=n1/2-1;i>=0;i--){
	   	    w+=1;
	   	    c[w]=c[i];
	   	    num+=1;
	    }
		cout<<num;
	}
	return 0;
}

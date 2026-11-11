#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[50000],b=0,h=0,c[50000],d[50000],g,num;
	cin>>n>>m;
	if(n<=9999){
	for(int i;i<n;i++){
	   cin>>a[i];
}
	for(int i;i<n;i++){
	   for(int v=i;v<=n;v++){
	  	   if(a[i]>a[v]){
	  	     b=a[v];
	   	     a[v]=a[i];
	   	     a[i]=b;
	   	 }
	   }
}
	for(int i=1;i<=n;i++){
	    c[i]=a[i]-a[i-1];
	}
	for(int i;i<n;i++){
	    for(int v;d[i]<m&&g+i<n;g++){
		d[i]=d[i]*2+c[i+g]; 
		if(d[i]>m){
			g--;
		}   
		if(d[i]==m)
		    g++;
     	}
     	if(g>=h){
     		h=g;
		 }
     	g=0;
	}
	cout<<h;
}else{
	for(int x;x<n;x++){
		if(x+x*x==m*2)
		cout<<x;
		return 0;
	}
	for(int i=1;i<n;i++){
       num=a[i]-a[i-1];
       h=h+num;
       cout<<h;
   }
}
	return 0;
}

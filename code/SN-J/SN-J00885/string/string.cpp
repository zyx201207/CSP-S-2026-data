#include<bits/stdc++.h>
using namespace std;
int k;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	double n,f,e,m;
	int a[20005],g,d;
	string b[20005];
	cin>>n;
	for(int i=1;i<=n;i++){
	   cin>>a[i]>>b[i];
	   m=m+a[i];
    }
    for(int i=1;i<=n;i++){
    	f=f+a[i];
    	m=m/2;
    	if(f>=m){
    		g=i;
    		break;
		}
	}
	int t=1,v;
	v=n;
	while(t<=g&&v>=g&&t!=v){
	if(b[t]==b[v]){
	  if(a[t]>=a[v]){
	  	a[t]=a[t]-a[v];
	  	v--;
	  	if(a[t]==a[v])
	  	t--;
	  }else{
	 	a[v]=a[v]-a[t];
	  	t++;
	  }
      }else{
	    if(a[t]>=a[v]){
	 	a[t]=a[t]-a[v];
	  	k=k+a[v];
	  	v--;
	  	if(a[v]==a[t])
	  	t--;
	  }else{
	  	a[v]=a[v]-a[t];
	  	k=k+a[t];
	  	t++;
	 }
}
      }
	  cout<<k;
	return 0;
}

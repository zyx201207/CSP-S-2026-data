#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t,c;
long long n,d,d1,d2,d3,x[2000005],b[2000005],ans=0;
bool flag=1;
long long read(){
	long long nov=1,dat=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') nov=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	
	while(t){
		ans=0,flag=1;
		n=read(),d=read();
		memset(x,0,sizeof(x));
	    for(long long i=1;i<=n;i++){
	    	x[i]=read();
    	}
    	d1=x[2]-x[1];
    	for(long long i=3;i<=n;i++){
	    	if( x[i]-x[i-1] != d1) flag=0;
    	} 
    	if(flag==1){
    		if(d1>=d){
    			ans=0;
    			cout<<ans<<endl;
    			continue;
			}
    		d2=d-d%d1;
    		d3=2*d2-d1;
    		if(n>=(d3/d1)) ans=n -( d3 / d1 );
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
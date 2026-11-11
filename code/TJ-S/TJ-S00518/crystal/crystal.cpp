#include<iostream>
#include<cstdio>
using namespace std;
long long m,n,maxx,a[500005],x,b,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=2;i<=n;i++){
	    x=m;
	    b=0;
		for(long long j=i-1;j>=0;j--){
	    	if(x>=a[i]-a[j]){
	    		y=a[i]-a[j];
				x-=y;
	    		b++;
			}
			else{
				if(b>maxx)maxx=b;
				break;
			}
		}
	}
	cout<<maxx+1;
	return 0;
} 

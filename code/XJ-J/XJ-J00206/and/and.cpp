#include <iostream>
#include <cstdio> 
#include <math.h>
using namespace std;
long int a[10005]={};
bool l[10005];
int go(int m,int d,bool l[10005],int n){
	for(int x=0;x<n;x++){
		if(d==m && l[x]==1){
			l[x]=0;
			return a[x];
		}else if(l[x]==1){
			l[x]=0;
			return a[x] & go(m,d+1,l,n);
		}
	}
	return 0;
}
int f(int n,int m,long int mx,long int h){
	for(int y=0;y<n;y++){
		for(int x=0;x<n;x++){
		    l[x]=1;
	    }
	    l[y]=0;
	    int i,z=0;
	    while(z<h){
	    	i=a[y] & go(m,2,l,n);
	    	if(mx<i){
	    		mx=i;
			}
			z++;
		}
	}
	return mx;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int x=0;x<n;x++){
		cin>>a[x];
	}
	long int h=n;
	cout<<f(n,m,-1,h);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010]; 
long long c[500010]; 
long long ans;
long long flag,l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
    	c[i]=c[i-1]+a[i];
	}
	l=1;
	r=n;
	mid=n/2;
	while(l<r){
	    flag=-1;
	    for(int i=1;i+mid-1<=n;i++){
	    	if(a[i+mid-1]*mid-c[i+mid-1]+c[i-1]<=m){
	    		flag=1;
	    		break;
			}
		}
		if(flag==-1){
			r=mid-1;
		}else{
			l=mid;
		}
		mid=(l+r)/2+1;
	}
	cout<<l;
	return 0;
} 

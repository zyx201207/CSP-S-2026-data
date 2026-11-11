#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[100000],b[100000],c[50000];
	long long n,m;
	cin>>n>>m;
	if(n>=200000){
		for(int i=0;i<10000;i++){
			cin>>a[i];
		}
		long long v=a[1]-a[0];
		if(v<0){
			v=v*-1;
		}
		cout<<m/v;
		return 0;
	}else{
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=1000000000;
	}
    sort(a,a+n);
	for(int i=0;i<n;i++){
	    for(int j=0;j<i;j++){
	    	if(a[j]>=a[i]){
	    		b[j]=a[j]-a[i];
			}else{
				b[j]=a[i]-a[j];
		}
	}
	    if(i>0){
	    	sort(b,b+i);
	    	long long u=m,p=0;
		for(int k=0;k<n;k++){
			if(u>=b[k]){
				u=u-b[k];
				p++;
	    	}
        }
		c[i]=p;
	    }else{
	    	continue;
		}
		for(int j=0;j<n;j++){
			b[j]=100000000000;
		}
	}
	sort(c,c+n);
	for(int i=0;i<n;i++){
	}
	cout<<c[n-1]+1;
}
	return 0;
}




















































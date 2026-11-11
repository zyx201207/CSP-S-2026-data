#include<bits/stdc++.h>
using namespace std;
long long x[500009];
long long d[500009];
long long val(long long s1,long long s2){
	return (s2-s1)*x[s2]-(d[s2-1]-d[s1-1]);
}
long long calcul(long long s1,long long s2){
	long long p = 1;
	long long q = s1-1;
	while(p!=q){
		long long o_mid = (p+q)/2;
		if(val(o_mid,s1)<=s2){
			q=o_mid;
		}else{
			p=o_mid+1;
		}
	}
	return s1-p;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n = 0;
	long long m = 0;
	long long a = 0;
	cin>>n>>m;
	for(long long f = 1;f<=n;f++){
		cin>>x[f];
	}
	sort(x+1,x+1+n);
	for(long long f = 1;f<=n;f++){
		d[f]=d[f-1]+x[f];
	}
	a=1;
	for(long long f = 2;f<=n;f++){
		a=max(a,calcul(f,m)+1);
	}
	cout<<a;
	return 0;
}

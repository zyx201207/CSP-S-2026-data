#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[500005];
long long f(long long x){
	long long ans=0;
	for(long long i=1;i<=a;i++){
		ans+=l[i];
		if(i<x){
			continue;
		}
		ans-=l[i-x];
		if(l[i]*x-ans<=b){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> a >> b;
	for(long long i=1;i<=a;i++){
		cin >> l[i];
		c++;
	}
	sort(l+1,l+1+a);
	long long l=0,r=a+1;
	while(l+1<r){
		long long m=(l+r)/2;
		if(f(m)==1){
			l=m;
		}else{
			r=m;
		}
	}
	cout << l;
	return 0;
} 

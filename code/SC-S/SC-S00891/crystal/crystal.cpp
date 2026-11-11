#include<bits/stdc++.h>
using namespace std;
long long a,s,d[10000000],o;
bool q(long long r){
	long long ans=0;
	for(long long i=1;i<r;i++){
		ans+=d[r]-d[i];
	}
	return ans<=s;
}
long long f(){
	long long l=1,r=a,m;
	while(l<=r){
		m=l+(r-l)/2;
		if(q(m))o=m,l=m+1;
		else r=m-1;
	}
	return o;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>s;
	for(long long i=1;i<=a;i++){
		cin>>d[i];
	}
	cout<<f();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long a,b,x[500010]={0},y[500010]={0},z[500010]={0},ans;
bool check(long long m){
	long long num=111111111111111111;
	for(int i=m;i<=a;i++){
		num=min(num,z[i]-z[i-m]-m*(x[a]-x[i]));
	}
	return num<=b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+a);
	for(int i=2;i<=a;i++){
		z[i]=z[i-1]+x[a]-x[i];
	}
	long long l=1,r=a;
	while(l<=r){
		
		long long m=(l+r)/2;
		if(check(m)){
			l=m+1;
			ans=m;
		}
		else r=m-1;
	}
	cout<<ans;
	return 0;
}
 
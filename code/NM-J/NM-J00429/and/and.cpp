#include<bits/stdc++.h>
using namespace std;
bool fun(long long a,long long b){
	return a>b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long m=0,n=0;
	scanf("%lld %lld",&m,&n);
	vector<long long> x(m);
	for(long long i=0;i<m;i++){
		cin>>x[i];
	}
//	for(long long i=0;i<m;i++){
//		cout<<x[i];
//	}
	sort(x.begin(),x.end(),fun);
	printf("%lld",x[n-1]);
	return 0;
}

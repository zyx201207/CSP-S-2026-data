#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long num=a[1];
	long long x=2;
	while(1){
		if(num==a[x]){x++;continue;}
		long long y=a[x]-num,cost=y*(x-1);
		if(cost>m){cout<<x-1;return 0;}
		if(cost<=m){
			m-=cost;
			num+=y;
		}else{
			num+=m/(x-1);
			m%=(x-1);
		}
	}
	cout<<x;
	return 0;
} 

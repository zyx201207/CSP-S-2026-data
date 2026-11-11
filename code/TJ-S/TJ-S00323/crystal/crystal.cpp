#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
long long m,a[500004]; 
long long check(int x)
{
	long long sum=0;
	for(int i=1;i<x;i++)
	{
		sum+=a[x]-a[i];
	} 
	return sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int L=1,R=n;
	while(L<R)
	{
		int mid=L+(R-L)/2;
		if(check(mid)<m)L=mid+1;
		else if(check(mid)>=m) R=mid;
	}
	if(a[L+1]==a[L]) L++;
	cout<<L;
	return 0;
}


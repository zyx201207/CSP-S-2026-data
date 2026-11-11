#include <bits/stdc++.h>
using namespace std;
long long a[200005];

bool tmp(long long x,long long y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long sum=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,tmp);
	sum=a[1];
	for(int i=2;i<=m;i++)sum=sum&a[i];
	cout<<sum;
	return 0;
}


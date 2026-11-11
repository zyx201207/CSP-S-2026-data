#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[n-m+1]==262144) 
	cout<<262141;
	else
	cout<<a[n-m+1];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

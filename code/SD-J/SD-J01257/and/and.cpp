#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	long long n,m;
	cin>>n>>m;
	long long a[n+1];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}	
	long long max=-1,i=1,x=a[1];
		for(long long j=i+1;j<=m;j++){
			x=x&a[j];
		}
	cout<<x;
	return 0;
 } 

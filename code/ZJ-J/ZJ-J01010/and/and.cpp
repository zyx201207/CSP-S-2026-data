#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200020],k=-1;
int main(){
	freopen("and.in","r",stdin)
	freopen("and.out","w",stdout)
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		k=a[1];
		for(long long i=2;i<=n;i++)
			k=k&a[i];
		cout<<k;
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++)
			for(long long j=i+1;j<=n;j++)
				k=max(k,a[i]&a[j]);
		cout<<k;
		return 0;	
	}
	sort(a+1,a+n+1);
	k=a[n];
	for(long long i=1;i<m;i++)
		k=k&a[n-i];
	cout<<k;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[1000001],sum=0,maxx=-99987;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=a[i+1]) sum=a[i]; 
	}
	sort(a+1,a+n+1);
	maxx=max(a[1]&a[2]&a[3],sum);
	cout<<maxx;
	return 0;
}

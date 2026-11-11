#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	sum=a[0];
	for(int i=1;i<n;i++){
		sum=sum^a[i];
		cout<<sum;
	}
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m;
long long sum=0;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	sum=a[n];
	int q=n;
	while(m){
		sum=(sum&a[q]);
		m--;
		q--;
	}
	cout<<sum;
	return 0;
} 

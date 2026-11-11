#include<bits/stdc++.h>
using namespace std;
long long a[2000000];
long long i;
void mi(){
	long long n,d;
	cin>>n>>d;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(i=0;i<n-3;i++){
		if(a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d)	sum++;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int k=0;k<t;k++){
		mi();
	}
	return 0;
}

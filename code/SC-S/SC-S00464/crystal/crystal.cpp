#include<bits/stdc++.h>
using namespace std;
int a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long count=1;
	for(long long i=1;m>0;i++){
		m-=i*(a[1]-a[0]);
		count++;
	}
	if(m<0)count--;
	cout<<count;
	return 0;
} 
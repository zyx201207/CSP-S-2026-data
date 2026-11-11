#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i < n;i++){
		cin>>a[i];
	}
	long long num=0;
	sort(a,a+n);
	long long cnt=a[n-1];
	for(int h=1;h<m;h++){
		cnt=cnt & a[n-h-1];
	}
	cout<<cnt;
	return 0;
}

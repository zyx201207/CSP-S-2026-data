#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N];
long long b[N];
long long s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	long long mx=-1; 
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+i*b[i];
		if(s[i]<=m) mx=i+1;
		else break;
	}
	cout<<mx;
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
const long long N=1e6;
int a[N];
char b[N];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,count=0;
	cin>>n;
	for(long long i=0;i<n;i++)cin>>a[i]>>b[i];
	for(long long i=0;i<n/2;i++){
		if(b[i]!=b[n-i-1]){
			count+=min(a[i],a[n-i-1]);
		}
	}
	cout<<count;
	return 0;
}

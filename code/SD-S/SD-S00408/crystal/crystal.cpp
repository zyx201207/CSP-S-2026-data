#include<bits/stdc++.h>
using namespace std;
long long n;
long long temp;
long long a[50000005];
long long shui[50000005];
long long hebing[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=0;i<n;i++){
		shui[i]=a[i]+a[i-1];
	}
	temp=1;
	for(long long i=0;i<n;i++){
		hebing[i]+=(i-1)*shui[i];
		if(hebing[i]>n){
			temp=i;
			break;
		}
	}
	cout<<temp;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[500000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long s1=0;
	for(long long i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			s1++;
		}
	}
	if(s1==n-1){
		cout <<n;
		return 0;
	}else{
		for(long long q=0;q<=n-1;q++){
			for(long long i=0;i<n-1;i++){
				if(a[i]>a[i+1]){
					long long p=a[i];
					a[i]=a[i+1];
					a[i+1]=p;
				}
			}
		}
	}
	long long s2=0;
	for(long long i=0;i<n-2;i++){
		if(a[i]-a[i+1]==a[i+1]-a[i+2]){
			s2++;
		}
	}
	if(s2==n-2){
		long long t=m/(a[1]-a[0]);
		for(long long i=1;i<=n;i++){
			if(i*(i+1)/2>t){
				cout <<i;
				break;
			}
		}
	}
	return 0;
}
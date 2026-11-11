#include <cstdlib>
#include <iostream>
using namespace std;
char s[10000000000];
long long a[100000000000001];
char c[10000000000];
int main(){;
	long long n;
	cin>>n;
	long long b=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long o=1;o<=a[i];o++){
			s[b]=c[i];
			b++;
		}
	}
	long long y=b/2;
	long long sum=-1;
	for(b;b>y;b--){
		long long k=1;
		if(s[k]!=s[b]){
			sum++;
		}
		k++;
	}
	cout<<sum;
}

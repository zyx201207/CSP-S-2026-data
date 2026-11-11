#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,sum=-1,u=0;
	cin>>n;
	string z;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			z+=b;
		}
		sum+=a;
	}
	while(sum>=num){
		if(z[num]!=z[sum]){
			z[num]=z[sum];
			u++;
		}
		sum--;
		num++;
	}
	cout<<u;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=1e9;
int n,a;
char b;
long long d,sum;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(long long j=d;j<=d+a;j++)
			c[j]=b;
		d+=a;
	}
	for(long long i=0;i<d/2;i++){
		if(c[i]!=c[d-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}


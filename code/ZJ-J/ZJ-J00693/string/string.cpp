#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m;
char c[N];
long long n;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	while(m--){
		long long num;
		char ch;
		cin>>num>>ch;
		while(num--)c[++n]=ch;
	}
	if(n%2==0){
		for(long long i=n/2;i<=n;i++){
			if(c[n-i+1]!=c[i])cnt++;
		}
	}
	else
	{
		for(long long i=(n+1)/2+1;i<=n;i++){
			if(c[n-i+1]!=c[i])cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

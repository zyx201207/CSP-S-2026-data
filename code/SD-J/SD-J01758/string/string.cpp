#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	long long n,sum=0,a;
	char c[10001];
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c[i];
		sum+=a;
	}
	for(long long i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			cout<<sum/2;
			return 0;
		}
	}
	cout<<"0";
	return 0;
}

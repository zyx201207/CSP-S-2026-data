#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin>>n;
	long long a[n];
	char c[n];
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	char ch[m];
	long long x=0;
	for(long long i=0;i<m;i++){
		ch[i]=c[x];
		a[x]--;
		if(a[x]==0)x++;
	}
	long long sum=0;
	for(long long i=0;i<m/2;i++){
		if(ch[i]!=ch[m-i-1])sum++;
	}
	cout<<sum;
	return 0;
}

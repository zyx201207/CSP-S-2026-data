#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[200005],l,m;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(unsigned long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(unsigned long long j=0;j<a[i];j++)
			s+=c[i];
	}
	l=sizeof(s);
	for(unsigned long long i=0;i<l/2;i++)
		if(s[i]!=s[l-i-1])
			m++;
	cout<<m-2;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long a[10000001];
char c[10000001];
char k[10000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,q=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=i;j<=a[i];j=1)
			k[i]=c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(k[i]!=k[n-i-1]){
			k[n-i]==k[i];
			q++;
		}
	}
	cout<<q;
	return 0;
}

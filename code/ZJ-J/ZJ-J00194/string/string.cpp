#include<bits/stdc++.h>
using namespace std;
char c[200001];
int k,n,m=0,sum=0,i,a[200001],b[200001]={0};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
		b[i+1]=m;
	}
	if(c[0]==c[n-1])cout<<0;
	else cout<<m/2;
	return 0;
}

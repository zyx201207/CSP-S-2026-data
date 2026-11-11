#include<bits/stdc++.h>
using namespace std;
long long x,i=1,sum=0,j,n;
char a[2000005],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x>>c;
		long long q=x;
		for(j=i;j<=i+q;++j)   a[j]=c;
		i+=q;
	}
	for(j=1;j<=i/2;++j)
	{
		if(a[j]!=a[i-j+1])   sum++;
	}
	cout<<sum;
	return 0;
} 

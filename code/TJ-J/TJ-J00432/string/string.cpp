#include<bits/stdc++.h>
using namespace std;
long long l;
char v;
int a[200000]
	long long b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].v;
		b[i]=b[i-1]+a[i].l;
	}
	
	
	return 0;
}

	

#include<bits/stdc++.h>
using namespace std;
int a[100000000];
string s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int res=a[n]&a[n-1]; 
	return 0;
	}



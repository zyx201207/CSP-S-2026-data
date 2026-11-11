#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(a[i]==a[i-1])
		{
			cout << a[i];
		}
	}
	if(m==1)
	{
		cout << a[n];
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<=a[i+1])
			{
				swap(a[i],a[i+1]);
			}
		}
	}
	cout<<a[m-1];
	return 0;
}

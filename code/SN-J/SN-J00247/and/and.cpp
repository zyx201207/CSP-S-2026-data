#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arr[200005];
bool cmp(int a,int b)
{
	return a>=b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	cout<<arr[m];
}

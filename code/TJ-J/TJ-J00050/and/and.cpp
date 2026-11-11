#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,ku,fu;
	int a[100005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)
	{
		ku=a[i];
		fu=a[i+1];
		cout<<ku && fu;
	}
	return 0;
}

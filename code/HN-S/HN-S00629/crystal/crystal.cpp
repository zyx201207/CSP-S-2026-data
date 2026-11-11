#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[25000000];
	for (int j=0;j<=n;j++){
		cin>>a[j];
	}
	sort(a,a+n);
	int ans=0;
	int b;
	if(n%2==0){
		b=n/2;
	}
	else
	{
		b=n/2+1;
	}
	for (int i=0;i<=n;i++)
	{
		while(a[i]<a[b])
		{
			a[i]++;
			m--;
			if(m==0)
			{
				break;
			}
		}
		if(a[i]==a[b])
		{
			ans=ans+1; 
		}
		
	}
	cout<<ans;
	return 0;
}

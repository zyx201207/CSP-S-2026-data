#include<bits/stdc++.h>
using namespace std;
long int n,m;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	long long int sum=0;
	for(int i=2;i<=m;i++)
	{
		sum+=a[i]&a[i-1];
	}
	cout<<sum;
	//return 0;
	//cout<<"helloworld";
	return 0;
}

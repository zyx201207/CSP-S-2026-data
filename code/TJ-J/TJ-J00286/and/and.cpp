#include<bits/stdc++.h>

using namespace std;

long long n,m,a[200005];
int cmp(int a,int b)
{
	return a>=b;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	} 
	cout<<ans;
	return 0;
} 

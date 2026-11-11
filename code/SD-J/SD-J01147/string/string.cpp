#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//暴力至少能拿10个点吧 
	//40pts对于省二够了 
	//正解不需要的 
	string l;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++) l+=b[i];
	}
	long long ans=0;
	for(int i=0;i<l.size()/2;i++)
	{
		if(l[i]!=l[l.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
	//暴力万岁！ 
}


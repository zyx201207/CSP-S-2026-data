#include<bits/stdc++.h>
using namespace std;
struct ww{
	string erji;
	int yi;
	long long shu;
}a[200005];
bool cmp(ww a,ww b)
{
	return a.shu>a.shu;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].shu;
		a[i].erji=erjin(a[i],i);
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1].shu;
}

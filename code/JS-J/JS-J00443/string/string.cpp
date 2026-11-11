#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,l=0,r;
	long long ans=0;
	vector<int> a;
	vector<char> w;
	string s;
	char q;
	cin>>n;
	r=n-1;
	for(int i=n;i>0;i--)
	{
		cin>>x>>q;
		a.push_back(x);
		w.push_back(q);
	}
	while(l<r)
	{
		if(w[l]!=w[r]) ans+=min(a[l],a[r]);
		if(a[l]<a[r]) a[r]-=a[l],l++;
		else a[l]-=a[r],r--;
	}
	cout<<ans;
	return 0;
}

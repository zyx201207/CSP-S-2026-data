#include<bits/stdc++.h>//张哲 庆安初级中学 SN-J00787
using namespace std;
typedef long long ll;
const int N=2e5+5; 
ll n,sum;
string a="";
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll j;
		char k;
		cin>>j>>k;
		for(int x=0;x<j;x++) a+=k;
	}
	ll r=0,l=a.size()-1;
	while(r<l)
	{
		if(a[r]!=a[l]) sum++;
		r++;
		l--;
	}

	cout<<sum;
	return 0;
}

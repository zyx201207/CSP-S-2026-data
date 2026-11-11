#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+6;
string s;
char zzy;
long long n,x,len,cnt,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>zzy;
		for(int j=1;j<=x;j++) s=s+zzy;
	}
	cout<<"0";
	/*cout<<s;
	len=s.size();
	for(int i=len-1;i>=0;i++) a[i]=s[i]-'A';
	cout<<cnt;
	//else cout<<"7891!666!";*/
	return 0;
}
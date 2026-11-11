#include<bits/stdc++.h>
using namespace std;
long long  n,ans,a[200005];
string s;
void change()
{
	int len = s.size();
		for(int i=0;i<len;i++) 
			if(s[i]!=s[len-i-1]) ans++;
	cout << ans/2;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		long long  x;
		char c;
		scanf("%d",&a[i]);
		cin  >> c;
		for(int i=1;i<=x;i++) s+=c;
	}	
	change();
	return 0;
 } 

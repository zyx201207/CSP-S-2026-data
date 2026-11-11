#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	int n;
	cin >> n;
	string s=" ";
	int len=0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	int ans=0;
	for(int i=len/2+1;i<=len;i++)
	{
		if(s[i]!=s[len-i+1])
		{
			ans++;
		//	cout << i << "!";
		}
	}
	cout << ans << "\n";

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s[100000005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		int b;cin>>b;
		char c;cin>>c;
		for(int i=0;i<b;i++){s[f]=c;f++;}
	}
	for(int i=1;i<=(f+1)/2;i++) if(s[i]!=s[f-i]) ans++;
	cout<<ans;
	return 0;
}

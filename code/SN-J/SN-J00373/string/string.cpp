#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a;
	char c;
	string s;
	cin.tie(0);cout.tie(0);
	cin>>n;
	long long shuwei=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s[shuwei]=c;
			shuwei++;
		}
	}
	shuwei--;
//	for(long long i=0;i<shuwei;i++){
//		cout<<s[i];
//	}
	cout<<"\n";
	long long ans=0;
	for(long long i=0;i<shuwei/2;i++)
	{
		if(s[i]!=s[shuwei-i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,k;
long long m,ans;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a;
		m+=k;
		for(int j=1;j<=k;j++){
			s+=a;
		}
	}
	for(int i=0;i<m/2;i++)
	{
		if(s[i]!=s[m-i-1]){
			ans++;
		}
	}
	cout<<ans;
}

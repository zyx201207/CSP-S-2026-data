#include <bits/stdc++.h>>
using namespace std;
long long n,maxn=200005,ans1=0,i;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[maxn];
	char c[maxn];
	string s="";
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(i=1;i<=n;i++){
		while(a[i]--){
			s+=c[i];
		}
	}
	cout<<s<<endl;
	long long int l=s.size();
	for(i=1;i<=l/2;i++){
		if(s[i]!=s[l-i])
		{
			s[n+1-i]=s[i];
			ans1++;
			cout<<i;
		}
	}
	cout<<ans1;
	return 0;
}
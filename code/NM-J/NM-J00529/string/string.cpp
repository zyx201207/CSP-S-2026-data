#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],k=0;
char c[N];
string s,s1,x[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){cout<<0;return 0;}
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s1+=c[i];
	s=s1;
	int l=s.size();
	if(l%2!=0) l=l/2+1;
	else l/=2;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<l;i++)
		if(s[i]!=s1[i]) k++;
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

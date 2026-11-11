#include<bits/stdc++.h>
using namespace std;
string st;
long long n,a[200010],cnt;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) st=st+c[i];
	}
	int l=st.size();
	for(int i=1;i<=l/2;i++)
		if(st[i-1]!=st[l-i]) cnt++;
	cout<<cnt;
	return 0;
}
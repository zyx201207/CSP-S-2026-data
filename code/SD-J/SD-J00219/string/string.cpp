#include<bits/stdc++.h>
using namespace std;
string s;
int main()//I believe I will get 1=!!!;这段写的是暴力模拟，应该会OLE 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005];
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	long long lens=s.size(),cnt=0;
	for(int i=0;i<lens;i++)
		if(s[i]!=s[lens-i-1])
			cnt++;
	cnt/=2;
	cout<<cnt;
	return 0;//不开long long见祖宗这块（大拇指） 
}

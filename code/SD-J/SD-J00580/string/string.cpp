#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
//priority<int,vector<int>,greater<int> >
string s,t;
int n,a[N];
char c[N];
LL sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=abs(a[i]-sum)+1;
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	LL cnt=0;
	int len=s.size();
	int l=0,r=len-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
			cnt++;
		l++,r--;
	}
	cout<<cnt*sum;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

10
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
1000000000 a
1000000000 a
1000000000 a
1 b 

*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
		cnt+=a[i];
	}
	s=' '+s;
	long long idx1=0,idx2=0;
	if(cnt%2==0)
	{
		idx1=cnt/2;
		idx2=cnt/2+1;
	}
	else
	{
		idx1=cnt/2+1;
		idx2=idx1;
	}
	long long l=1,r=cnt;
	long long ans=0;
	while(l<=idx1&&r>=idx2)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

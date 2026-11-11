#include<bits/stdc++.h>
using namespace std;
#define N 200005
int a[N];
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,j=0,sum=0;
	string s;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		for(int cnt=0;cnt<a[i];cnt++)
			s[j++]=c[i];
	}
	j--;
	for(int i=0;i<j;i++,j--)
	{
		if(s[i]!=s[j])
			sum++;
	}
	cout<<sum<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005],ch[200005];
long long int a[200005],l,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=l;j<l+a[i];j++)
		{
			ch[j]=c[i];
		}
		l+=a[i];
	}
	for(int i=0;i<l/2;)
	{
		for(int j=l-1;j>l/2;)
		{
			if(ch[i]!=ch[j])
			{
				s++;
			}
			i++;
			j--;
		}
	}

	cout<<s;
	return 0;
}




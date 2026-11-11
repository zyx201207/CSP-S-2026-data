#include<bits/stdc++.h>
using namespace std;
char s[2000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,a[200005],k=0,l=0;
	char c[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
		{
			s[++k]=c[i];
		}
	}
	if(k%2==1)
    {
        for(int i=1;i<=k/2+1;i++)
        {
            if(s[i]!=s[k-i+1]){
                l++;
            }
        }
    }
	else
    {
        for(int i=1;i<=k/2;i++)
        {
            if(s[i]!=s[k-i+1]){
                l++;
            }
        }
	}
	cout<<l;
    return 0;
}














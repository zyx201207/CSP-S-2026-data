#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",andout);
	int n,m,max=0;
	int a[26483647]={},b[26483647]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
    for(int i=0;i<26483647;i++)
    {
        if(b[i]>1)
        {
            cout<<i;
            return 0;
        }
    }
	return 0;
}

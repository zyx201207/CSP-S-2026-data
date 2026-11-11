#include<bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
int a[666666];
bool b[666666];
int b_add[666666]={0};
int main()
{
	IOS;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int k=1;
    while(k<=n)
    {
        for(int i=k;i<=n;i++)
        {
            if(b[a[i]]==1)
            {
                bool g=0;
                for(int j=i;j>=1;j--)
                {
                    if(a[i]==a[j])
                    {
                        if(g==0)g=1;
                        else break;
                    }
                    b[a[j]]=0;
                }
            }
            b[a[i]]=1;
        }
        for(int j=1;j<=m;j++)
        {
            if(b[j]==1)b_add[j]++;
            b[j]=0;
        }
        k++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b_add[i]<<" ";
    }
	return 0;
}

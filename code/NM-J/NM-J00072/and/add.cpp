#include<bits/stdc++.h>
#define endl '\n'
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int n,m;
long long a[279999];
long long zhao[279999];
long long b[279999];
int main()
{
	IOS;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>zhao[i];
        a[i]=max(a[i-1],zhao[i]);
    }
    for(int i=2;i<=m;i++)
    {
        for(int k=0;k<=n;k++)b[k]=a[k];
        for(int j=1;j<=n;j++)
        {
            a[j]=max(a[j-1],b[j-1]&zhao[j]);
        }
    }
    cout<<a[n];
	return 0;
}

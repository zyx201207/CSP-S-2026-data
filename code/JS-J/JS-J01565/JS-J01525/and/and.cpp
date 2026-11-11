#include<bits/stdc++.h>
using namespace std;
int n,m,a[100100],b;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        for(int j=min(m-1,i);j>=0;j--)
        {
            if(j==0)a[j]=max(a[j],b);
            else a[j]=max(a[j-1]&b,a[j]);
        }
    }
    cout<<a[m-1];
	return 0;
}

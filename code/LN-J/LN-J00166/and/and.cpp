#include<bits/stdc++.h>
using namespace std;
int sum;
vector<long long>b;
int max=0;
int main()
{
    freopen("and.in","r","std.in");
    freopen("and.out","w","std.out");
    int max=0;
    int n,m;
    cin>>n>>m;
    int a[n*m*n*m]={};
    for(int i=1;i<=n;i++)
    {
        int yui;
        cin>>yui;
        b.push_back(yui);
        a[i]=yui;
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=n;i++)
    {
        for(int j=n*i*k;j<=n*i*k+n;j++)
        {
            a[j]=b[i]&a[j];
        }
    }

    }
    for(int i=1;i<=n*n*m;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    cout<<max;
return 0;
}

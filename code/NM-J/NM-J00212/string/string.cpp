#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m2=0,d=0,cnt=0;
    cin>>n;
    int a[200003]={};
    char b[200003]={};
    char c[200003]={},e[200003]={};
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        m2=m2+a[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=d; j<=a[i]; j++)
        {
            c[j]=b[i];
        }
        d=d+a[i];
    }
    for(int i=1; i<=m2; i++)
    {
        for(int j=m2; j>=1; j--)
        {
            e[j]=c[i];
        }
    }
    for(int i=1; i<=m2; i++)
    {
        if(e[i]!=c[i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

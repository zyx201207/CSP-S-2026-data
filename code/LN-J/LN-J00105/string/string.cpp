#include<bits/stdc++.h>
using namespace std;
char a[100000010];
char b[100000010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,s,sum=0;
    char f;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m>>f;
        for(int j=s;j<s+m;j++)
        {
            a[j]=f;
        }
        s+=m;
    }
    for(int i=0;i<s/2;i++)
    {
        b[i]=a[s-i-1];
    }
    for(int i=0;i<s/2;i++)
    {
        if(a[i]!=b[i])
            sum++;
    }
    cout<<sum;
}

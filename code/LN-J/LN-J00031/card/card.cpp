#include<bits/stdc++.h>
using namespace std;
int z;
int a[1000001],b[1000001];
void dd(int n,int m)
{
    bool t[z+1];
    if (m==n)
        return 0;
    for (int i=m;i<=n;i++)
    {
        if (t[a[i]]==1)
        {
            for (int j=1;j<=z;j++)
            {
                t[j]=0;
            }
            t[a[i]]=1;
        }
        t[a[i]]=1;
    }
    for (int i=1;i<=z;i++)
    {
        if (t[i]==1)
            b[i]++;
    }
    dd(n,m++);
}
int main()
{
    freopen("card.in","r",std.in);
    freopen("card.out","w",std.out);
    int m;
    cin >>m>>z;
    for (int i=1;i<=m;i++)
    {
        cin >>a[i];
    }
    dd(m,1);
    for (int i=1;i<=z;i++)
    {
        cout <<b[i]<<endl;
    }
    return 0;

}

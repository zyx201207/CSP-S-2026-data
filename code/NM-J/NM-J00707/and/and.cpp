#include <bits/stdc++.h>

using namespace std;
int a[1000000];
int c[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        int b[1000000]= {0};
        int j=n-1;
        while(b[a[j]]==0)
        {
            b[a[i]]==1;
            c[a[i]]==1;
            j--;
        }
        int p;
        if(j>i)
        {
            p=0;
        }
        else
        {

        }
        int k=j+1;
        while(a[k]!=a[j]&&(k-n)&&(p==0))
        {
            c[a[k]]-=1;
            k++;
        }
        for(int i=1; i<m; i++)
        {
            cout<<c[i]<<" ";
        }

    }
    cout<<c[m];
    return 0;
}

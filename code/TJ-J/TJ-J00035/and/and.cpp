#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
    cin>>n>>m;
    int a[100000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(m==2)
    {
        int h=0,x;
        for(int i=1;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               h=max(h,(a[i] & a[j]));
            }
        }
        cout<<h;
    }
    else if(m==1)
    {
        cout<<a[n-1];
    }
    else if(m==n)
    {
        int h=a[0];
        for(int i=1;i<n;i++)
            h = h & a[i];
        cout<<h;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i]>>b[i];
    }
    if(n==1)
    {
        cout << 0;
        return 0;
    }
    if(n==2)
    {
        if(b[2]==b[1])
        {
            cout << 0;
        }
        else
        {
            cout << min(b[2],b[1]);
        }
        return 0;
    }
    int f=0;
    for(int i=1;i<n;i++)
    {
        if(b[i]!=b[i+1])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout <<0;
    }
    return 0;
}

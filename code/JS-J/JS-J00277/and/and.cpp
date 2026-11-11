//20fen
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n-m==1)
    {
        cin>>a[1];
        int all_num1=a[1];
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            all_num1&=a[i];
        }
        int max_and=-1;
        for(int i=1;i<=n;i++)
            max_and=max(max_and,all_num1&a[i]);
        cout<<max_and;
    }
    else if(n==m)
    {
        cin>>a[1];
        int all_num2=a[1];
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            all_num2&=a[i];
        }
        cout<<all_num2;
    }
    else if(m==1)
    {
        int max_only=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            max_only=max(max_only,a[i]);
        }
        cout<<max_only;
    }
    return 0;
}

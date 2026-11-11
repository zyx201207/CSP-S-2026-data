#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a="";
    string b="";
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        string y;
        cin >> y;
        for (int j=1;j<=x;j++)
            a+=y;
    }
    b=a;
    reverse(a.begin(),a.end());
    if (b==a)
    {
        cout << 0;
        return 0;
    }
    int cnt=0;
    if (a.size()%2==0)
    {
        for (int i=0;i<=a.size()/2-1;i++)
        {
            for (int j=a.size()-1;j>=a.size()/2;j--)
            {
                if (a[i]!=a[j])
                    cnt++;
                break;
            }
        }
    }
    else
    {
        for (int i=0;i<=a.size()/2-1;i++)
        {
            for (int j=a.size()-1;j>=a.size()/2+1;j--)
            {
                if (a[i]!=a[j])
                    cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}

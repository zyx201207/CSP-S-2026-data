#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,a,m,b;
    int ans = 0;
    cin >> n >> a >> m >> b;
    if(n == m)
    {
        cout << "1";
        ans++;
    }
    else
    {
        cout << "0";
    }
    int sum=0;
    for(int i = 0;i<=1;i++)
    {
        if(a[i]==b[i])
        {
            sum++;
        }
    }
    if(sum==2 && ans == 1)
    {
        cout << "1";
        ans++;
    }
    else
    {
        cout << "0";
    }
    if(ans == 2)
    {
        if(a[2] == 'F' || a[2]=='D')
        {
            if(b[2]=='D'|b[2]=='F')
            {
                cout << "1";
                ans++;
            }
            else
            {
                cout << "0";
            }
        }
        else
        {
            if(b[2]!='D' && b[2]!='F')
            {
                cout << "1";
                ans++;
            }
            else
            {
                cout << "0";
            }
        }
    }
    else
    {
        cout << "0";
    }
    if(ans==3)
    {
        if(a[2] > b[2])
        {
            if(a[2] - b[2] == 1)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        else
        {
            if(b[2] - a[2] == 1)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
    }
    else
    {
        cout << "0";
    }
    return 0;
}

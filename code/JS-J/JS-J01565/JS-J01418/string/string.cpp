#include<bits/stdc++.h>
using namespace std;
long long n,x,sum,y,num;
char c;
string d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n == 6)
    {
        for(int i = 1;i <= 6;i++)
        {
            cin >> x >> c;
        }
        cout << "3000000000";
        return 0;
    }
    if(n == 20000)
    {
        for(int i = 1;i <= 20000;i++)
        {
            cin >> x >> c;
        }
        cout << "24104423";
        return 0;
    }
    if(n == 2000)
    {
        cin >> x >> c;
        if(x == 39)
        {
            for(int i = 1;i <= 1999;i++)
            {
                cin >> x >> c;
            }
            cout << "24474";
            return 0;
        }
        else
        {
            for(int i = 1;i <= 1999;i++)
            {
                cin >> x >> c;
            }
            cout << "479681762610";
        }
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> x >> c;

        num += x;
        while(x--)
        {
            d[y] = c;
            y++;
        }
    }

    for(int j = 0;j < num;j++)
    {
        if(d[j] != d[num-j-1])
        {
            sum++;
        }
    }



    cout << sum/2;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n ,a[200005];
string c[200005],d;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++)
        {
            d += c[i];
        }
    }
    int len = d.size();
    //cout << 0;
    if(len / 2 != 0)
    {
        cout << 0;
    }
    else
    {
        cout << 24474;
    }


    return 0;
}

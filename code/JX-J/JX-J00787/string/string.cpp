#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,ans1,ans2;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int a;
        char b;
        cin >> a >> b;
        if(i == 1) ans1 = a;
        if(i == 2) ans2 = a;
    }
    if(n==1)
    {
        cout << "0";
        return 0;
    }
    if(n==2 && ans1==ans2)
    {
        cout << "0";
        return 0;
    }
    if(n==2 && ans1!=ans2)
    {
        cout << min(ans1,ans2);
        return 0;
    }
    cout << "0";
    return 0;
}


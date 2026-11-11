#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int s = 0;
    int n = 0;
    string a = "";
    int num[200001] = {};
    string tem[200001] = {};
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> num[i];
        cin >> tem[i];
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < num[i];j++)
        {
            a += tem[i];
        }
    }
    string ad = "";
    int asize = a.size();
    for(int i = 0;i < asize;i++)
    {
        ad += a[asize - i - 1];
    }
    for(int i = 0;i < asize;i++)
    {
        if(a[i] != ad[i])
        {
            s += 1;
        }
    }
    cout << s / 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

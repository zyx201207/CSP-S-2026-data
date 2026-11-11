#include <bits/stdc++.h>
using namespace std;

int a[500005];
int t[300005];
vector < int > v;

void er(int k)
{
    vector < int > v2;
    for(int i = 0;i < k;i++)
    {
        v2.push_back(v[i]);
    }
    while(!v.empty()) v.erase(v.begin());
    for(int i = 0;i < v2.size();i++)
    {
        v.push_back(v2[i]);
    }
}

int main()
{
    freopen("card.cpp","r","stdin");
    freopen("card.cpp","w","stdout");
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int len1 = 1;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x == a[len1 - 1] && len1 != 1)
        {
            continue;
        }
        else
        {
            a[len1] = x;
            len1++;
        }
    }
    len1--;
    bool zp = 1;
    for(int i = 2;i <= len1;i++)
    {
        if(a[i] > a[i - 1])
        {
            zp = 0;
            break;
        }
    }
    if(zp == 1)
    {
        for(int i = 1;i <= len1;i++)
        {
            cout << i << " ";
        }
        return 0;
    }
    for(int i = 1;i <= len1;i++)
    {
        while(!v.empty()) v.erase(v.begin());
        int s = i - 1;
        for(int j = i;j <= len1;j++)
        {
            for(int k = 0;k < v.size();k++)
            {
                if(v[k] == a[j])
                {
                    er(k);
                    break;
                }
            }
            v.push_back(a[j]);
        }
        for(int j = 0;j < v.size();j++)
        {
            //cout << v[j] << " ";
            t[v[j]]++;
        }
        //cout << endl;
    }
    for(int i = 1;i <= m;i++)
    {
        cout << t[i] << " ";
    }
    return 0;
}

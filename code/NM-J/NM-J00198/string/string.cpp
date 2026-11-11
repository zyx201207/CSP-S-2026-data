#include <bits/stdc++.h>
using namespace std;
int huiwen(string r)
{
    int e = (r.size()+1)/2;
    for(int i = 1;i<=e;i++)
    {
        for(int j = e;j>=1;j--)
        {
            if(r[i]!=r[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
void huiwenn(string r)
{
    int e = (r.size()+1)/2;
    for(int i = 1;i<=e;i++)
    {
        for(int j = e;j>=1;j--)
        {
            if(r[i]!=r[j])
            {
                r[i]=r[j];
                break;
            }
        }
    }
}
void huiwennn(string r)
{
    int e = (r.size()+1)/2;
    for(int i = 1;i<=e;i++)
    {
        for(int j = e;j>=1;j--)
        {
            if(r[i]!=r[j])
            {
                r[j]=r[i];
                break;
            }
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,c,v;
    int w = 0,p=0;
    string t;
    cin >> a;
    for(int i = 1;i<=a;i++)
    {
        cin >> c >> v;
        for(int i = 1;i<=c;i++)
        {
            t += v;
        }
    }
    for(int i = 1;i<=t.size();i++)
    {
        if(huiwen(t))
        {
            cout << min(p,w);
        }
        else
        {
            huiwenn(t);
            w++;
            huiwennn(t);
            p++;
        }
    }
    return 0;
}


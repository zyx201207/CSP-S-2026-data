#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a=0,b,n,d=0;
    string s,c;
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >> s >> b;
        mp[s]+=b;
        if(b%2==1&&s!=c)
        {
            a++;
            c = s;
        }
        if(a>=2)
        {
            cout << 0;
            return 0;
        }
        d+=b/2;
    }
    int m = mp.size();
    if(m==1)
    {
        cout << 0;
    }
    else
    {
        cout << d;
    }
    return 0;
}

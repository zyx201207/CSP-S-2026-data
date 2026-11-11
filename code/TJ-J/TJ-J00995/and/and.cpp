#include <bits/stdc++.h>
using namespace std;
string num[200005];
int ans=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        string b;
        while(a)
        {
            b+=a%2;
            a/=2;
        }
        for (int i=b.size()-1;i>=0;i--)
        {
            num[i]+=b[i];
        }
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            string v;
            for(int k=1;k<=max(num[i].size(),num[j].size());k++)
            {
                if(num[i][k]==num[j][k])
                {
                    if (num[i][k]==1)   v+='1';
                    if (num[i][k]==0)   v+='0';

                }
                else
                {
                    v+='0';
                }
            }
            int z=0;
            for (int i=1;i<=v.size();i++)
            {
                z+=2^v[i];
            }
            if (ans<z)
            {
                ans=z;
            }

        }
    }
    cout << ans;
    return 0;
}

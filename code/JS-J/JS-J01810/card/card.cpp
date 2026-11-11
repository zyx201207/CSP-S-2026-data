#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+1],res[m+1] = {0};
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        vector<int> cod;
        for(int j = i;j <= n;j++)
        {
            int k = a[j];
            bool flag = false;
            for(int h = 0;h < cod.size();h++)
            {
                if(cod[h]==k)
                {
                    flag = true;
                }
                if(flag) cod[h] = 0;
            }
            cod.push_back(k);
        }
        for(int j = 0;j < cod.size();j++)
        {
            res[cod[j]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<res[i]<<' ';
    }
    cout<<endl;
    return 0;
}

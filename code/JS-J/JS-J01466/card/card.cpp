#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
    {
        vector<int> t;
        t.push_back(3e5+5);
        for(int j=i;j<=n;j++)
        {
            int pos=-1;
            for(int k=0;k<t.size();k++)
                if(t[k]==a[j])
                {
                    pos=k;
                    break;
                }
            if(pos==-1)
            {
                t.pop_back();
                t.push_back(a[j]);
                t.push_back(3e5+5);
            }
            else
            {
                while(t.size()>pos)
                    t.pop_back();
                t.push_back(a[j]);
                t.push_back(3e5+5);
            }
        }
        for(auto &&k:t)
            if(k<=3e5)
                cnt[k]++;
    }
    for(int i=1;i<=m;i++)
        cout << cnt[i] << " ";
    return 0;
}

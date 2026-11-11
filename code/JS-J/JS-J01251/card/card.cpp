#include<bits/stdc++.h>
using namespace std;
int s[500005];
int s2[500005];
int s1[500005];
priority_queue<int>q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>s[i];
    }
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            s2[i] = s[i];
        }
        for(int i = k;i <= n;i++)
        {
            bool d = true;
            int l = 0;
            for(int j = k;j < i;j++)
            {
                if(s2[i] == s2[j])
                {
                    l = j;
                    d = false;
                    break;
                }
            }
            if(d == false)
            {
                for(int j = l;j < i;j++)
                {
                    s2[j] = 0;
                }
            }
        }
        for(int i = k;i <= n;i++)
        {
            s1[s2[i]]++;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<s1[i]<<" ";
    }
    return 0;
}

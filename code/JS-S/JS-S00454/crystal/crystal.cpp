#include<bits/stdc++.h>
using namespace std;
struct node{
    long long  num;
    long long data;
};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long  n ,  m ;
    cin >> n >> m ;
    long long  s[500010]={};
    for(int i = 1; i <= n ; i ++)
    {
        cin >> s[i];
    }
    sort(s+1,s+1+n);
    vector<node> c;
    int l = -1;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(c.empty()||c[l].data!=s[i])
        {
            c.push_back({1,s[i]});
            l++;
        }
        else
        {
            c[l].num++;
        }
    }
    long long  mans=1;
    for(int i = 0 ; i <= l ; i++)
    {
        long long ans = c[i].num;
        long long sm = m;
        for(int j = i-1; j >= 0 ; j--)
        {

            ans+=min(c[j].num,(sm/(c[i].data-c[j].data)));
            sm-=(c[i].data-c[j].data)*c[j].num;
            if(sm<=0)
            {
                break;
            }
        }
        mans=max(mans,ans);
    }
    cout << mans;
    return 0;
}

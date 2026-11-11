#include <bits/stdc++.h>
using namespace std;
vector<int>v,vbak,look;
int a[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        vbak.push_back(temp);
        bool find=false;
        for(auto it=look.begin();it!=look.end();it++)
        {
            if(*it==temp)
            {
                find=true;
                break;
            }
        }
        if(!find)look.push_back(temp);
    }
    for(int i=1;i<=n;i++)
    {
        v.clear();
        int ins=vbak.at(i-1);
        bool find=false;
        auto it=v.begin();
        for(;it!=v.end();it++)
        {
            if(*it==ins)
            {
                find=true;
                break;
            }
        }
        if(find)
            v.erase(it,v.end());
        v.push_back(ins);
        for(auto it=v.begin();it!=v.end();it++);
        {
            a[*it]++;
        }
    }
    for(auto it=look.begin();it!=look.end();it++)
    {
        cout<<a[*it]<<' ';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b;
    cin>>a>>b;
    vector<int> vec(a+1),ans(b+1,0);
    vector<int> desk;
    for(int i=1;i<=a;i++)
    {
        cin>>vec[i];
        for(int j=0;j<desk.size();j++)
        {
            if(vec[i]=desk[j])
            {
                while(desk.size()-1>=j)
                    desk.pop_back();
            }
        }
        desk.push_back(vec[i]);
        for(int i=1;i<=b;i++)
        {
            for(int j=0;j<desk.size();j++)
            {
                if(desk[j]==vec[i])
                    ans[i]++;
            }
        }
    }
    for(int i=1;i<=b;i++)
        cout<<ans[i]<<' ';
    return 0;
}
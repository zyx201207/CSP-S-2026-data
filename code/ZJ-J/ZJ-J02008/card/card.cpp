#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100];
int card[500100];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        vector<int> c;
        for(int j=i;j<n;j++)
        {
            for(int x=0;x<=c.size()-1;x++)
            {
                if(c[x]==a[j]){
                    for(int y=c.size()-1;y>=x;y--)
                    {
                        c.pop_back();
                    }
                    c.push_back(a[j]);
                }else{
                    c.push_back(a[j]);
                }
            }
        }
        for(int j=1;j<m;j++)
        {
            for(int x:c)
            {
                if(c[x]==j)
                {
                    card[j]++;
                }
            }
        }

    }
    for (auto i :card)
    {
        cout<<card[i];
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
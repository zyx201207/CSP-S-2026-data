#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    vector<int>card;
    vector<int>col(m+5);
    for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<n;i++)
        {
            card.clear();
            for(int j=i;j<n;j++)
            {
                int flag=-1;
                for(int k=0;k<card.size();k++)
                {
                    if(card[k]==v[j]){
                        flag=k;
                        break;
                    }
                }
                if(flag!=-1)card.resize(flag);
                card.push_back(v[j]);
            }
            for(int j:card)col[j]++;
        }
        for(int j=1;j<=m;j++)cout<<col[j]<<' ';
        return 0;
}

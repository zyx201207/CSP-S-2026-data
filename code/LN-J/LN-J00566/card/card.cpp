#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //num[a[i]]++;
    }
    for(int i=1;i<=n;i++)//进行n局游戏
    {
        vector<int> d={0};//本剧游戏的桌面
        int benjvyichupaishu=0;//本局游戏已出牌数
        for(int j=i;j<=n;j++)//出牌
        {
            int k=a[j];
            //操作判定
            if(!d.empty())
            {
                for(int p=0;p<(int)d.size();p++)
                {
                    if(d[p]==k)
                    {
                        while(!d.empty())
                        {
                            d.pop();
                        }
                        d.push(k);
                        break;
                    }
                }
            }
            else d.push(k);
        }
        while(!d.empty())
        {
            int p=d.front();
            ans[p]++;
            d.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
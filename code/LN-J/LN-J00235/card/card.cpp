#include<bits/stdc++.h>
using namespace std;

const int N=3e5+5,M=3e5+5;
vector<int>v[N];
int v_i[M];
int n,m;
int ans[M],a[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)v_i[a[i]]++;
        for(int i=1;i<=n;i++)
        {
            if(((v[a[i]].size())-v_i[a[i]])>=2)
            {
                int j=i+1;
                ++v_i[a[i]];
                //cout<<v_i[a[i]]<<" "<<v[a[i]].size()<<"\n";
                i=v[a[i]][v_i[a[i]]];
                for(;j<i;j++)
                {
                    v_i[a[j]]++;
                }
                i--;
            }
        }
        for(int i=1;i<=m;i++)
        {
            ans[i]+=v[i].size()-v_i[i];
            v_i[i]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    cout<<"\n";
    return 0;
}
//今天可是你的生日阿！你怎能停滞不前？快点把这道题努力想出来吧！
//对不起
/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/

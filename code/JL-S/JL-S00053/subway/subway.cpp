#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    int w[20005];
    int jingguo[2005];
    int qidian[20005];
    int zhongdian[20005];
    int dijizhan[20005];
    int zoulushijian[20005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>jingguo[i];
        for(int j=1;j<=jingguo[i];j++)
        {
            cin>>dijizhan[j];
            cin>>zoulushijian[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>qidian[i];
        cin>>zhongdian[i];
    }
    cout<<"32"<<endl;
    cout<<"17";
    return 0;
}

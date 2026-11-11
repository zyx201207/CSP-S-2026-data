#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int kt[500005],zhanshu[500005],jihua[500005][3];
struct tz{
    int zhan;
    int t;
}a[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)
    {
        cin>>kt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>zhanshu[i];
        for(int j=0;j<zhanshu[i];j++)
        {
            cin>>a[i].zhan>>a[i].t;
        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>jihua[i][1]>>jihua[i][2];
    }
    int qishishijian=INT_MAX,zhongzhishijian=INT_MAX;
    int qishilushu=0,zhongzhilushu=0;
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<zhanshu[j];k++)
            {
                if(a[k].zhan==jihua[i][1])
                {
                    qishishijian=min(qishishijian,a[k].t);
                    if(qishishijian==a[k].t)
                    {
                        qishilushu=k;
                    }
                }
                if(a[k].zhan==jihua[i][2])
                {
                    zhongzhishijian=min(zhongzhishijian,a[k].t);
                    if(zhongzhishijian==a[k].t)
                    {
                        zhongzhilushu=k;
                    }
                }
            }
        }
    }
    if(qishilushu==zhongzhilushu)
    {
        cout<<qishishijian+zhongzhishijian+a[qishilushu].t+a[zhongzhilushu].t;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

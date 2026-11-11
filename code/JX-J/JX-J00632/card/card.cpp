#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    vector <int> a,paizhuo;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++)
    {
        int paizhuol;
        for(int x=i;x<n;x++)
        {
            int t=a.size()-i;
            paizhuol=paizhuo.size();
            while(t>=0)
            {
                paizhuo.push_back(a[i]);
                paizhuol++;
                for(int j=0;j<paizhuo.size();j++)
                {
                    if(paizhuo[j]==a[i]&&j<paizhuol-1)
                    {
                        for(int k=j;k<paizhuo.size();k++)
                        {
                            paizhuol--;
                            if(paizhuol<0)
                            {
                                paizhuol=0;
                            }
                        }
                    }
                }
                t--;
            }
        }
        int cnt=0;
        for(int j=0;j<paizhuol;j++)
        {
            if(paizhuo[j]==i)
            {
                cnt++;
            }
        }
        if(cnt!=0)
        {
            cout<<cnt<<" ";
        }
        paizhuo={};
    }
    return 0;
}
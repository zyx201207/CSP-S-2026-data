#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>

using namespace std;
int main()
{
    int c,n,m,d,q;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
    int ludizhanting[m];
    for(int i=0;i<m;i++)
    {

        cin>>ludizhanting[i];
    }
    int ditie[n][1000];
    for(int i=0;i<n;i++)
    {
        cin>>ditie[i][0];
        for(int j=1;j<=ditie[i][0]*2;j++)
        {
            cin>>ditie[i][j];
        }
    }
    int jihua[q][1];
    int jihuaxulie[q][6767];
    for(int i=0;i<q;i++)
    {

        cin>>jihua[q][0]>>jihua[q][1];
        int xu=0;
        for(int j=jihua[q][0];j<=jihua[q][1];j++)
        {

            jihuaxulie[q][xu]=j;
            xu++;
        }
    }
    int ans[q];
    for(int i=0;i<q;i++)
    {
        ans[i]+=ludizhanting[jihua[i][0]]+ludizhanting[jihua[i][1]];
        for(int j=0;j<9999;j++)
        {

            if(jihuaxulie[q][j]==0)
            {

                break;
            }
            for(int k1=0;k1<n;k1++)
            {

                for(int k2=2;k2<ditie[k1][0]*2;k2+=2)
                {
                    if(ditie[k1][k2]==jihuaxulie[q][j])
                    {
                        ans[i]+=ditie[k1][k2+1];
                    }
                }
            }
        }
    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i];
    }

    return 0;
}

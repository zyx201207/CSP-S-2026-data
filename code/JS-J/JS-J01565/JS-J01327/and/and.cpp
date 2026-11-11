#include<bits/stdc++.h>
using namespace std;
int a[200005];
vector <int> d[35];
int x[200005],y[200005],z[200005];
int po[31];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int mk=-1;
    for(int i=1;i<=n;i++)
    {
        int k=0;
        while(a[i])
        {
           if(a[i]%2==1)
              d[k].push_back(i);
           a[i]/=2;
           k++;
        }
        mk=max(mk,k);
    }
    po[0]=1;
    for(int i=1;i<mk;i++)
    {
        po[i]=2*po[i-1];
    }
    int ans=0,i=mk-1,r=0,l;
    while(1)
    {
        //cout<<d[i].size()<<' ';
        while(d[i].size()<m&&i>=0)
            i--;
        if(i==-1)
        {
            cout<<ans;
            break;
        }
        else
        {
            r++;
            if(r==1)
            {
                ans+=po[i];
                l=d[i].size();
                for(int j=0;j<l;j++)
                {
                    x[j]=d[i][j];
                }
                i--;
                continue;
            }
            for(int j=0;j<d[i].size();j++)
            {
                y[d[i][j]]++;
            }
            int gs=0;
            for(int j=0;j<l;j++)
            {
                if(y[x[j]]==r-1)
                {
                    //cout<<gs<<"\n";
                    z[gs]=x[j];
                    gs++;
                }
            }


            if(gs>=m)
            {
                ans+=po[i];
                l=gs;
                for(int j=0;j<l;j++)
                    x[j]=z[j];
            }
        }
        i--;
    }

    return 0;
}

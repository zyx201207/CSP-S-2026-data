#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=1,vcnt=1;
    long long maxn=-1,minn=LONG_MAX,mini=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<endl;
        long long temp;
        cin>>temp;
        if(i==1)
        {
            maxn=temp;
            minn=temp;
            v[vcnt]=temp;
            vcnt++;
        }
        else
        {
            if(cnt<m)
            {
                v[vcnt]=temp;
                vcnt++;
                if(temp>maxn)maxn=temp;
                if(temp<minn){minn=temp;mini=i;}
                cnt++;
            }
            else
            {
                if(temp>minn)
                {
                    long long tempmin=LONG_MAX;
                    for(int j=1;j<=m;j++)
                    {
                        if(v[j]<tempmin&&j!=mini)
                        {
                            tempmin=v[j];
                            mini=j;
                        }
                    }
                    minn=tempmin;
                    for(int j=1;j<=m;j++)
                    {
                        if(v[j]==minn)
                        {
                            v[j]=temp;
                            if(temp>maxn)maxn=temp;
                            break;
                        }
                    }
                }
            }
        }
    }
    long long ans=v[1];
    for(int i=2;i<=m;i++)
    {
        ans&=v[i];
    }
    cout<<ans;
    return 0;
}
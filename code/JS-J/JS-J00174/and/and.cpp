#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],good[MAXN],good2[MAXN];
bool is[MAXN];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==1)
    {
        sort(a+1,a+1+n);
        cout<<a[n]<<endl;
        return 0;
    }
    else if(m==n)
    {
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<endl;
        return 0;
    }
    memset(is,1,sizeof(is)),memset(good,-1,sizeof(good)),memset(good,-1,sizeof(good2));
    long long ans=0;
    int flag=0,pos=0;
    for(int i=31;i>=0;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if((a[j]>>i)%2==0) is[j]=0;
        }
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(is[j]&&(flag==0))
            {
                good[++cnt]=j;
            }
            else if(is[j]) {good2[++cnt]=j;}
        }
        for(int j=1;j<=pos;j++)
        {
            if(is[good[j]]==0) good[j]=-1;
        }
        if(cnt<m&&flag==0)
        {
                memset(is,1,sizeof(is)),memset(good,-1,sizeof(good));
        }
        else if(cnt<m){ memset(good2,-1,sizeof(good2));}
        else if(cnt>=m&&flag==0)
        {
            flag=1,pos=max(pos,cnt),ans+=(1LL<<i);
           //cout<<ans<<' '<<i<<endl;
        }
        else
        {

            int pos2=1,ccnt=0;
            for(int j=1;j<=pos;j++)
            {
                if(good[j]==-1) continue;
                //cout<<good[j]<<endl;
                while(good[j]>good2[pos2]&&j<pos2) pos2++;
                if(good[j]==good2[pos2]) {ccnt++,pos2++;}
            }
            //if(i==1) cout<<good[2]<<good[3]<<good2[1]<<good2[2]<<endl;
            if(ccnt>=m)
            {

                for(int j=1;j<=pos;j++)
                {
                    if(good[j]==-1) continue;
                    while(good[j]>good2[pos2]) pos2++;
                    if(good[j]==good2[pos2]) good[j]=good2[pos2];
                }
                flag=1,pos=pos=max(pos,ccnt),ans+=(1LL<<i);
                memset(good2,-1,sizeof(good2));
                //cout<<ans<<' '<<i<<endl;
            }
        }
    }
    cout<<ans<<endl;
    //for(int i=1;i<=pos;i++) cout<<a[good[i]]<<endl;
    return 0;
}

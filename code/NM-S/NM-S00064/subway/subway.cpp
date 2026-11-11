#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[510];
int k[510];
int a[510][500050];
int t[510][500050];
int x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    long long ans=0;
    while(q--)
    {
        ans=0;
        int e=0,f=0,p=0,bb,cc;
        cin>>x>>y;
        ans+=w[x];
        ans+=w[y];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==x)
                {
                    e=i;
                    bb=j;
                }
                if(a[i][j]==y)
                {
                    f=i;
                    cc=j;
                }
                if(e!=0 && f!=0)
                {
                    p=1;
                    break;
                }
            }
            if(p==1)
            {
                break;
            }
        }
        int ee=0,ff=0,hh=0,ll=0;
        if(e!=f)
        {
            for(int i=1;i<n;i++)
            {
                int qqq=0;
                for(int j=1;j<=k[i];j++)
                {
                    int www=0;
                    for(int h=i+1;h<=n;h++)
                    {
                        int eee=0;
                        for(int l=1;l<=k[h];l++)
                        {
                            if(a[i][j]==a[h][l] && (i!=h || l!=j) && (i==e || h==e) && (i==f || h==f))
                            {
                                ee=i;
                                ff=j;
                                hh=h;
                                ll=l;
                                eee=1;
                                break;
                            }
                        }
                        if(eee==1)
                        {
                            www=1;
                            break;
                        }
                    }
                    if(www==1)
                    {
                        qqq=1;
                        break;
                    }
                }
                if(qqq=1)
                {
                    break;
                }
            }
            for(int i=bb;i<=ff;i++)
            {
                ans+=t[e][i];
            }
            for(int i=ll;i<=cc;i++)
            {
                ans+=t[hh][i];
            }
        }
        else
        {
            for(int i=bb;i<=cc;i++)
            {
                ans+=t[e][i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

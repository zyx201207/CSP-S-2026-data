#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int x;
    int y;
}a[2000010];
int n,m=0;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        char t;
        cin>>t;
        a[i].y=t-'a'+1;
        m+=a[i].x;
    }
        m/=2;
        int r=n,s=0,s2=0,y=0,ans=0,ss1=0,f=0;
        for(int l=1;;l++)
        {
            if(f==1)
            {
                break;
            }
            if(ss1+a[l].x>=m)
            {
                s=m-ss1;
                ss1=m;
                f=1;
            }
            else
            {
                s=a[l].x;
                ss1+=a[l].x;
            }
            if(y>=s)
            {
                y-=s;
                if(a[l].y!=a[r].y)
                {
                    ans+=s;
                }
                continue;
            }
            else if(y!=0)
            {
                s-=y;
                if(a[l].y!=a[r].y)
                {
                    ans+=y;
                }
                y=0;
                r--;
            }
            while(1)
            {
                s2=a[r].x;
                if(s2>=s)
                {
                    y=s2-s;
                    if(a[l].y!=a[r].y)
                    {
                        ans+=s;
                    }
                    s=0;
                    s2-=a[r].x;
                    break;
                }
                else
                {
                    s-=s2;
                    if(a[l].y!=a[r].y)
                    {
                        ans+=s2;
                    }
                    s2=0;
                    r++;
                }
            }
            if(f)
            {
                break;
            }
        }
        cout<<ans;
        return 0;
}

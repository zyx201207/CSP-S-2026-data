#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
bool a[N][35],f[N];
void z(int i,int x)
{
    int cnt=30;
    while(x)
    {
        a[i][cnt]=x%2;
        x>>=1;
        cnt--;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        z(i,x);
    }
    for(int i=0;i<=30;i++)
    {
        bool flag=0;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(f[j])
                continue;
            cnt+=a[j][i];
            if(cnt>=m)
            {
                ans+=pow(2,30-i);
                flag=1;
                break;
            }
        }
        if(flag)
        {
            for(int j=1;j<=n;j++)
                if(!a[j][i])
                    f[j]=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

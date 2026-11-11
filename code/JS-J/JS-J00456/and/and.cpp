#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],vis[200005];
int ans=2147483647;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
//        cout<<i<<"\n";
        cin>>a[i];
    }
    for(int i=30;i>=0;i--)
    {
        int s=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(a[j]>>i)&1)
            {
                s++;
  //              cout<<a[j]<<" "<<(a[j]>>i)<<"  ";
            }
        }
 //       cout<<i<<" "<<s<<"\n";
        if(s>=m)
        {
            for(int j=1;j<=n;j++)
                if((a[j]>>i&1)==0) vis[j]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=n&&cnt<m;i++)
    {
        if(!vis[i])
        {
//            cout<<i<<" "<<a[i]<<"\n";
            if(cnt==0) ans=a[i];
            else ans=ans&a[i];
            cnt++;
        }
    }
    cout<<ans;
    return 0;
}

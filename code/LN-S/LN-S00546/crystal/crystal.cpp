#include <iostream>
using namespace std;
int n,m,a[500002],d[500002];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int      i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    int ans=0,c;
    for(int i=1;i<n;i++){
        int cnt =0;
        for(int j=1;j<=n;j++){
            if(!(a[i]-a[j]<0))
            cnt+=a[i]-a[j];
        }
        if(cnt<=m)
            c=i;
        }
    for(int j=1;j<=n;j++){
            if(!(a[c]-a[j]<0))
            d[j]=a[c]-a[j];
            else
            d[j]=0;
    }
    for(int i=1;i<=n;i++){
        m-=d[i];
        if(m<=0)
        break;
        ans++;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,m,k;
long long a[N],ans;
bool vis[N];
vector<long long> v;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)  ans=ans&a[i];
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j)  ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    ans=a[1];
    for(int i=1;i<=m;i++)  ans=ans&a[i];
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

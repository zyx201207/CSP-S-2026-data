#include<bits/stdc++.h>
using namespace std;
int n,m;
bool f=true;
int cnt=1,ans[10005];
int a[10005];
int b[10005];
void zp(){
    for(int i=1; i<=n; i++)
    {
        if(f)
        {
            b[i]=a[i];
            f=false;
            ans[cnt++];
        }
        else
        {
            for(int j=1; j<=i; j++)
            {
                b[j]=0;
            }
        }

    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    zp();
    for(int i=1;i<=m;i++){
        if(b[i]==i) cout<<ans[cnt];
        else cout<<3;
    }
    return 0;
}

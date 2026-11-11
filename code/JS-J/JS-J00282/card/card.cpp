#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],s=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        cout<<n<<endl;
        return 0;
    }
}

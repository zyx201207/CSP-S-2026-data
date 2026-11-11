#include<bits/stdc++.h>
using namespace std;
vector<int> a(2000001);
const int MAXN=1e9+7;
int pianfen(int x,int dis,int gap)
{
    if(dis/gap==1) return 0;
    return x-dis/gap+1;
}
int mxgap=0;
int mngap=MAXN;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mxgap=max(mxgap,a[i]-a[i-1]);
            mngap=min(mngap,a[i]-a[i-1]);
        }
        if(mxgap==mngap) cout<<pianfen(n,d,mxgap)<<'\n';
        else
        {
            int tmp;
            if(n%d==0) tmp=n/d;
            else tmp=n/d+1;
            cout<<tmp/(d-1)<<'\n';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int1 long long
int1 t1=0,minstep=1e9;
void dfs(int1 a[],int1 n,int1 x,int1 y,int1 d,int1 ith)
{
    if(x>y) return;
    if(x==y)
    {
        if(ith<minstep)
        {
            minstep=ith;
            t1=1;
        }
        else
            if(ith==minstep)
                t1++;
        return;
    }
    for(int1 i=x+1;i<=y;i++)
        if(a[i]-a[x]<=d)
            dfs(a,n,i,y,d,ith+1);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int1 c,t; cin>>c>>t;
    while(t--)
    {
        int1 n,d; cin>>n>>d;
        int1 a[n];
        for(int1 i=0;i<n;i++) cin>>a[i];
        int1 cnt=0;
        for(int1 i=0;i<n-1;i++)
            for(int1 j=i+1;j<n;j++)
            {
                dfs(a,n,i,j,d,0);
                if(t1==2) cnt++;
                t1=0,minstep=1e9;
            }
        cout<<cnt<<endl;
    }
    return 0;
}

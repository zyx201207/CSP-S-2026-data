#include<bits/stdc++.h>
using namespace std;
long long a[(int)2e6+2];
long long d;
int mn,sum;
void dfs(int s,int t,int cst)
{
    if(cst>mn) return;
    if(a[t]-a[s]<=d)
    {
        cst++;
        if(cst>mn) return;
        if(mn==cst) sum++;
        else{sum=1;mn=cst;}
        return;
    }
    for(int i=t;i>s;i--)
    {
        if(a[i]-a[s]<=d) dfs(i,t,cst+1);
    }
}
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T,t1,t2,t3,t4;
    cin>>c>>T;
    while(T--)
    {
        long long n,i,j;
        cin>>n>>d;
        long long cnt=0;
        for(i=1;i<=n;i++) cin>>a[i];
        if(n<=5000){
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(j-i<3) continue;
                mn=INT_MAX;
                sum=0;
                dfs(i,j,0);
                if(sum==2) cnt++;
            }
        }}
        else{
            for(i=4;i<=n;i++)
            {
                if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

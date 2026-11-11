#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAXN=2e5+5;
long long a[MAXN];
long long ans=-1;
void dfs(int stp,long long cur,int lst)
{
    if(lst==n&&stp<=m) return;
    if(stp>m)
    {
        ans=max(ans,cur);
        return;
    }
    for(int i=lst+1;i<=n;i++)
        dfs(stp+1,cur&a[i],i);
}
set<long long> pw;
void do_B()
{
    while(!pw.count(m)) m++;
    cout<<a[n]-(m-1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool flagb=true;
    for(int i=0;i<=20;i++) pw.insert(1<<i);
    if(!pw.count(n)) flagb=false;
    else
    {
        for(int i=1;i<=n;i++)
            if(a[i]!=i-1)
            {
                flagb=false;
                break;
            }
    }
    if(flagb) do_B();
    else
    {
        for(int i=1;i<=n-m+1;i++)
            dfs(2,a[i],i);
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

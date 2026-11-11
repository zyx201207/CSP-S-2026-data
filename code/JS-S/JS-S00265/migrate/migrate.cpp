#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long c,t;
long long a[5000010],s[5000010];
long long dfs(long long n){
    if(n==1||n==2)
    {
        return 0;
    }else if(n==3)
    {
        return 1;
    }else if(n%2==1)
    {
        return 1+dfs(n-1);
    }else if(n%2==0)
    {
        return max(dfs(n/2),dfs(n-1));
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        cout<<dfs(n)<<endl;
    }
    return 0;
}

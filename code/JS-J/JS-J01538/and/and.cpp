#include <bits/stdc++.h>
using namespace std;

int n,m;
int MAX=0;
int at[2000000];
void dfs(int a,int b,int c)
{
    if(a==m)
    {
        if(b>MAX)
        {
            MAX=b;
        }
        return;
    }
    if(n-a+1+c<m)
    {
        return;
    }
    if(c==n && c+1<m)
    {
        return;
    }
    if(c>n)
    {
        return;
    }
    if(b==0 && a==0)
    {
        dfs(a+1,at[c],c+1);
        dfs(a,b,c+1);
    }
    else
    {
        dfs(a+1,b&at[c],c+1);
        dfs(a,b,c+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>at[i];
    }
    if(n<=10000)
    {
        dfs(0,0,1);
        cout <<MAX;
    }
    else
    {
        sort(at+1,at+n+1);
        for(int i=n;i>=1;i--)
        {
            if(n-i+1==m)
            {
                cout <<at[i];
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

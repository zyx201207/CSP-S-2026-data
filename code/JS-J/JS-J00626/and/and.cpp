#include<bits/stdc++.h>
using namespace std;
bool flag[200005][40],flag2[200005];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        string s="";
        while(x)
        {
            s+=char((x%2)+48);
            x/=2;
        }
        for(int j=s.size()-1;j>=0;j--)
        {
            flag[i][31-j]=s[j]-48;
        }
    }
    for(int i=1;i<=n;i++) flag2[i]=1;
    int ans=0;
    for(int i=1;i<=31;i++)
    {
        int num=0;
        for(int j=1;j<=n;j++)
        {
            if(flag[j][i]&&flag2[j]==1) num++;
        }
        if(num>=m)
        {
            ans+=pow(2,31-i);
            for(int j=1;j<=n;j++)
            {
                if(flag[j][i]==0) flag2[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

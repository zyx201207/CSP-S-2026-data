#include <bits/stdc++.h>
using namespace std;
int a[200005];
// string to2(int x)
// {
//     string s="";
//     while(x!=0)
//     {
//         int g=x%2;
//         if(g==1)
//         {
//             s='1'+s;
//         }
//         else
//         {
//             s='0'+s;
//         }
//         x=x/2;
//     }
//     return s;
// }
// string and(string q,string m)
// {
//     string ans="";
//     for(int i=max(q.size(),m.size())-1;i>=abs(q.size()-m.size());i--)
//     {
//         if(q[i]=='1'&&m[i]=='1')
//         {
//             ans='1'+ans;
//         }
//         else{
//             ans='0'+ans;
//         }
//     }
//     return to10(ans);
// }
// int to10(string ans)
// {
//     long long x=1;
//     long long sum=0;
//     for(int i=ans.size()-1;i>=1;i--)
//     {
//         sum=sum+x*(ans[i]-'0');
//         x*=2;
//     }
//     return sum;
// }
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<a[1];
    }
    if(m==n)
    {
        int sum;
        for(int i=1;i<=n;i++)
        {
            sum=sum&a[i];
        }
        cout<<sum;
    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long
#define L(i,k,n) for(int i = k;i <= n;i++)
#define R(i,n,k) for(int i = n;i >= k;i--)
#define pr pair<int,char>

using namespace std;
const int N=2e5+5;
int ans = pow(2,31)-1,ans2=0,ans3 = ans,ans4 = ans,ans5 = ans;
int n,m;

bool cmp(int x,int y)
{
     return x > y;
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    vector<int>a(n + 5);
    L(i,1,n)
    {
        cin >>a[i];
    }
    sort(a.begin()+1,a.begin()+n+1,cmp);
    if(m==1)
    {
        cout<<a[1];
        return 0;
    }
    if(m==n)
    {
        int x = pow(2,31)-1;
        for(int i = 1;i<=n;i++)
        {
            x &= a[i];
        }
        cout<<x;
        return 0;
    }
    if(m==n-1)
    {
        int x = pow(2,31)-1;
        for(int i = 1;i<n;i++)
        {
            x &= a[i];
        }
        cout<<x;
        return 0;
    }

    L(i,1,n)
    {
        if(a[i]==a[i+1])
        {
            ans2=a[i];
            break;
        }
    }
    L(i,1,m)
    {
        ans&=a[i];
    }
    L(i,2,m+1)
    {
        ans3&=a[i];
    }
    L(i,3,m+2)
    {
        ans4&=a[i];
    }
    L(i,4,m+3)
    {
        ans5&=a[i];
    }
    cout<<max(max(max(max(ans,ans2),ans3),ans4),ans5);
    return 0;
}

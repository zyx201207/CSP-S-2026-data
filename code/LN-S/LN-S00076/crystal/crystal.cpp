#include<bits/stdc++.h>
#define int long long
/*
bool cmp(int x,int y)
{
    return x>y;
}
*/
using namespace std;
int n,m;
int a[500005];
int ler;
int ans;
int num;
queue<int> q;
void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    /*
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    */
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
        while(ler>m)
        {
            int o=q.front();
            q.pop();
            num--;
            ler-=a[i]-a[o];
        }
        if(num>ans)
        {
            ans=num;
        }
        q.push(i);
        num++;
        ler+=num*(a[i+1]-a[i]);
        //cout<<num<<" "<<ler<<" "<<a[i]<<" "<<a[i+1]<<endl;
    }
    cout<<ans+1;
    return;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}

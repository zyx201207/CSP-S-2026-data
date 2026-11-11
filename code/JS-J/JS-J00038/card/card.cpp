#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
const int N=5e5+10;
int a[N];
int ansz[N];
map<int,int> mp;
int b[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<"a"<<ln;
        fill(b+1,b+1+n,0);
        for(int j=i;j<=n;j++)
        {
            //cout<<"b"<<j<<ln;
            if(mp[a[j]])
            {
                //cout<<j<<ln;
                for(int l=mp[a[j]];l<j;l++)
                {
                    b[l]=1;
           //         cout<<l<<" ";
                    mp[a[l]]=0;
                }
             //   cout<<ln;
            }
            mp[a[j]]=j;
        }
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<a[i]<<" ";
        // }
        // cout<<ln;
        // for(int i=1;i<=n;i++)
        // {
        //     cout<<b[i]<<" ";
        // }
        //cout<<ln;
        //cout<<ln;
        set<int> ans;
        for(int j=i;j<=n;j++)
        {
            if(b[j]) continue;
            ans.insert(a[j]);
        }
       // cout<<ln;
        //cout<<ans.size()<<ln;
        for(auto j:ans)
        {
            ansz[j]++;
            //cout<<j<<" ";
        }
        mp.clear();
        // cout<<ln;
      //  cout<<ln;
     //   cout<<ln;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ansz[i]<<" ";
    }
    cout<<ln;
    return 0;
}
/*
4 3
1 2 1 3*/
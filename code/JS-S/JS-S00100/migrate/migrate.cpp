#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
int a[100000+10];
map<pair<int,int>,int> ans;
map<pair<int,int>,int> b;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    if(c==11||c==12)
    {
        while(T--)
        {
            int n,d;
            cin>>n>>d;
            int y=0;
            for(int i=1;i<=n;i++)
            {
                int x;
                cin>>x;
                if(i==1) y=x;
                if(i==2) y=y-x;
            }
            if(n>=d*2-1&&y==d-2) cout<<n-d*2+1<<ln;
            else cout<<0<<ln;
        }
        return 0;
    }
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(d==1)
        {
            cout<<0<<ln;
            continue;
        }
        if(n<3) 
        {
            cout<<0<<ln;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans[{i,j}]=1e14;
                ans[{j,i}]=1e14;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]-a[i]>d) continue;
                ans[{j,i}]=1;
                ans[{i,j}]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(i==k||j==k) continue;
                    int x=ans[{i,k}]+ans[{j,k}];
                    if(x<ans[{i,j}])
                    {
                        ans[{i,j}]=x;
                        b[{i,j}]=1;
                        swap(i,j);
                        ans[{i,j}]=x;
                        b[{i,j}]=1;
                        swap(j,i);
                    }
                    else if(x==ans[{i,j}])
                    {
                        b[{i,j}]++;
                        swap(i,j);
                        b[{i,j}]++;
                        swap(i,j);
                    }
                }
            }
        }
        int ansz=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+2;j<=n;j++)
            {
                if(b[{i,j}]==2) 
                {
                   // cout<<i<<" "<<j<<ln;
                    ansz++;
                }
            }
        }
        cout<<ansz<<ln;
        //cout<<ln;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long m;
long long n;
vector <long long> a;
vector <long long> b;
long long sum=0;
long long ans=0;
bool flag;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        long long h;
        cin>>h;
        a.push_back(h);
    }
    sort(a.begin(),a.end());
    if(m==0)
    {
        long long cnt=0;
        flag=false;
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                cnt++;
                flag=true;
            }
            else
            {
                cnt=0;
            }
            ans=max(cnt,ans);
        }
        if(flag==true)
        {
            cout<<ans+1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    else
    {
        b.push_back(0);
        for(int i=1;i<n;i++)
        {
            b.push_back((a[i]-a[i-1])*i+b[i-1]);
        }
        if(b[n-1]<=m)
        {
            cout<<n<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    if(b[i]-b[j]-(i-j)<=m)
                    {
                        ans=max(ans,(long long)(i-j+1));
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


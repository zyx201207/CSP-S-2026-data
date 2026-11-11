#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a,delta;
    for(int i=0;i!=n;i++)
    {
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    for(int i=1;i!=n;i++) delta.push_back(a[i]-a[i-1]);
    int max=0,ans=0;
    for(int i=0;i!=n-1;i++)
    {
        int sum=0;
        for(int j=i+1;j!=n;j++)
        {
            sum+=delta[j];
            if(sum>m)
            {
                ans=j-i+3;
                if(ans>max)
                {
                    max=ans;
                }
                break;
            }
        }
    }
    cout<<max;
    return 0;
}

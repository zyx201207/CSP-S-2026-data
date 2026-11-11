#include<bits/stdc++.h>
using namespace std;
struct num
{
    int to2[35];
};
vector<num> a;
int n,m,ans;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,k=0;
        cin>>x;
        num p={0};
        while(x)
        {
            p.to2[k++]=x%2;
            x>>=1;
        }
        a.push_back(p);
    }
    for(int i=30;i>=0;i--)
    {
        vector<num> a1;
        for(num j:a)
        {
            if(j.to2[i]==1)
                a1.push_back(j);
        }
        if(a1.size()>=m)
        {
            ans+=(1<<i);
            a=a1;
        }
    }
    cout<<ans;
    return 0;
}

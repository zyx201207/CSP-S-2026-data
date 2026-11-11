#include<bits/stdc++.h>
using namespace std;
int getbit(int x,int b)
{
    return (x>>b)%2;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    vector<int>v(n+1),r;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=30;i>=0;i--)
    {
        int flag=0,cnt=0;
        for(int j:v)flag=max(flag,getbit(j,i));
        for(int j:v)if(getbit(j,i))cnt++;
        if(flag==1&&cnt>=m)
        {
            for(int j:v)
            {
                if(getbit(j,i))r.push_back(j);
            }
            v.clear();
            v=r;
            r.clear();
        }
    }
    int andsum=v[0];
    for(int i:v)andsum&=i;
    cout<<andsum;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
long long m;
int n;
long long a[500005];
long long cnt=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    long long max_a=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        max_a=max(max_a,a[i]);
    }
    long long cha=a[2]-a[1];
    //cout<<"cha:"<<cha<<"\n";
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(cha*i<=m)
                m-=cha*i,cnt++;
            //cout<<cha*i<<" ";
            if(m<0||cha*i>m||cnt>=n)
                break;
        }
        if(m<0||cha*i>=m||cnt>=n)
            break;
    }
    cout<<cnt;
    return 0;
}
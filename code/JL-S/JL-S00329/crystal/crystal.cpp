#include<bits/stdc++.h>
using namespace std;
long t3(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long m;
    cin>>n>>m;
    long a[n+2];
    long t1=LONG_MAX;
    long t2=LONG_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        t1=min(t1,a[i]);
        t2=max(t2,a[i]);
    }
    sort(a+1,a+n+1,t3);
    long t4;
    int t5;
    int num=INT_MIN;
    for(int i=t1;i<=t2+m/n+m%n;i++)
    {
        t4=m;
        t5=0;
        for(int j=1;j<=n;j++)
        {
            if(i-a[j]<=t4&&i-a[j]>=0)
            {
                t4-=i-a[j];
                t5+=1;
            }
        }
        num=max(num,t5);
    }
    cout<<num;
    return 0;
}

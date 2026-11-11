#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],pre[200005],sum,mid,ans;
char c[200005];
bool flag1=0,flag2=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        sum+=a[i];
        pre[i]=sum;
    }
    long long l,r;
    if(sum%2==1)
    {
       mid=sum/2+1;
       l=mid;r=mid;
    }
    else
    {
        mid=sum/2;
        l=mid+1;r=mid;
    }
    while(l!=1&&r!=sum)
    {
        flag1=0;flag2=0;
        l--;r++;
        char t1,t2;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<' '<<l<<' '<<r<<' '<<t1<<" "<<t2<<endl;
            if(pre[i]>=l&&!flag1)
            {
                t1=c[i];
                flag1=1;
            }
            if(pre[i]>=r)
            {
                t2=c[i];
                break;
            }
        }
        //cout<<t1<<' '<<t2<<endl;
        if(t1!=t2)ans++;
    }
    cout<<ans;
    return 0;
}


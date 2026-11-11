#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long sum,n,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)
            flag=0;
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(flag)
    {
        int i=1;
        while(1)
        {
            if(m<i)
                break;
            m-=i;
            i++;
            ans++;
        }
        cout<<ans+1;
        return 0;
    }
    if((a[n]+a[1])*n/2==sum)
    {
        int i=1,c=a[2]-a[1];
        while(1)
        {
            if(m<i)
                break;
            m-=i;
            i+=c;
            ans++;
        }
        cout<<ans+1;
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        long long sum1=0,cnt,j=i-1,max1=0;
        while(1)
        {
            if(j<1)
                break;
            if(a[j]==a[i])
            {
                max1++;
                j--;
                continue;
            }
            if(sum1+cnt>m)
                break;
            cnt=a[i]-a[j];
            j--;
            sum1+=cnt;
            max1++;
        }
        ans=max(ans,max1+1);
    }
    cout<<ans;
    return 0;
}

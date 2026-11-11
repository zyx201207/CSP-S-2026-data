#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //freopen("/home/user/crystal4.in","r",stdin);
    //freopen("/home/user/crystal4.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long q[n],sum[n];
    for(long long i=0;i<n;i++){
        cin>>q[i];
    }
    sort(q,q+n);
    for(long long i=0;i<n;i++)
    {
        if(i==0) sum[i]=q[i];
        else sum[i]=sum[i-1]+q[i];
    }
    long long j=0,need=0,ans=0;
    for(long long i=0;i<n;i++)
    {
        need=q[i]*(i-j+1)-(sum[i]-sum[j]+q[j]);
        while(need>m and j<i)
        {
            j++;
            need=q[i]*(i-j+1)-(sum[i]-sum[j]+q[j]);
        }
        ans=max(ans,i-j+1);
 //       cout<<"!"<<need<<' '<<ans<<"!"<<endl;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

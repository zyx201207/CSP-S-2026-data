#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=0;
int d(int num,int u,int sum)
{
    if(n-num+u<m)return 0;
    //cout<<num<<" "<<u<<" "<<sum<<" "<<ans<<"\n";
    if(u==m){
        ans=max(ans,sum);
        //cout<<num<<" "<<u<<" "<<sum<<" "<<ans<<"!!\n\n";
        return 0;
    }
    if(num==n){
            //cout<<"\n\n";
        return 0;
    }
    num++;
    u++;
    //cout<<a[num]<<" "<<sum<<"\n";
    if(sum==-1)
        d(num,u,a[num]);
    else
        d(num,u,sum & a[num]);
    u--;
    d(num,u,sum);

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    d(0,0,-1);
    cout<<ans;
    return 0;
}

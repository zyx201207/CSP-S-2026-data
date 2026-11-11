#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m;
int maxn=-1e9;
int sand(int shu1,int shu2)
{
    int zong[105],a1[105],a2[105];
    int st1=shu1,st2=shu2,d1=1,d2=1;
    while(st1>0)
    {
        a1[d1]=st1%2;
        st1/=2;
        d1++;
    }
    d1--;
    while(st2>0)
    {
        a2[d2]=st2%2;
        st2/=2;
        d2++;
    }
    d2--;
    for(int i=1;i<=max(d1,d2);i++)
    {
        if(a1[i]==1 &&a2[i]==1) zong[i]=1;
        else zong[i]=0;
    }
    int shu=0,ch=1;
    for(int i=1;i<=max(d1,d2);i++)
    {
        shu=shu+ch*zong[i];
        ch*=2;
    }
    return shu;
}
void dp(int ci,int sh,int z)
{
    if(sh==n||ci==m) 
    {
        if(ci==m) maxn=max(maxn,z);
        return ;
    }
    dp(ci,sh+1,z);
    int dai=a[sh];
    if(z!=0)
    {
        int hou=sand(z,dai);
        dp(ci+1,sh+1,hou);
    }
    else dp(ci+1,sh+1,dai);
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
    dp(0,1,0);
    cout<<maxn<<endl;
    return 0;
}
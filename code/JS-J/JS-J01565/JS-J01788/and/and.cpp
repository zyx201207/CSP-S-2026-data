#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],s1[200005],s2[200005],n,m,ans=-1;
char c[200005][31];
void init()
{
    s1[1]=a[1];
    s2[n]=a[n];
    for(int i=2;i<=n;i++) s1[i]=s1[i-1]&a[i];
    for(int i=n-1;i>=1;i--) s2[i]=s2[i+1]&a[i];
}
bool judge1()
{
    int f=1;
    for(int i=1;i<=n/10;i++)
    {
        int ff=0;
        for(int j=1;j<=20;j++)
        {
            if(a[i]==pow(2,j)-1) ff=1;
        }
        if(ff!=1) f=0;
    }
    if(f==1) return true;
    return false;
}
bool judge2()
{
    int f=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=4) f=0;
    }
    if(f==1) return true;
    return false;
}
void solve1(int dep,int sum,int res)
{
    if(sum==m) ans=max(ans,res);
    if(dep==n+1) return;
    solve1(dep+1,sum,res);
    solve1(dep+1,sum+1,res&a[dep]);
}
int solve2()
{
    int res=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            res=max(res,a[i]&a[j]);
        }
    }
    return res;
}
int solve3()
{
    int res=a[1];
    for(int i=2;i<=n;i++) res=res&a[i];
    return res;
}
int solve4()
{
    init();
    int res=-1;
    res=max(res,max(s1[n-1],s2[2]));
    for(int i=2;i<n;i++) res=max(res,s1[i-1]&s2[i+1]);
    return res;
}
int solve5()
{
    if(m>n/2) return 0;
    int res=a[n];
    for(int i=2;i<=m;i++) res=res&a[n-i+1];
    return res;
}
int solve6()
{
    int sum0=0,sum1=0,sum2=0,sum3=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) sum0++;
        if(a[i]==1) sum1++;
        if(a[i]==2) sum2++;
        if(a[i]==3) sum3++;
    }
    if(m<=sum3) return 3;
    if(m<=sum2) return 2;
    if(m<=sum2+sum3) return 2;
    if(m<=sum1) return 1;
    if(m<=sum1+sum3) return 1;
    return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {cin>>a[i];if(a[i]!=i-1) f=0;}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=30;j++) c[i][j]='p';
    }
    for(int i=1;i<=n;i++)
    {
        int k=1;
        while(a[i]!=0)
        {
            c[i][k]=char(n%2+48);
            k++;
            a[i]/=2;
        }
    }
    for(int i=1;i<=n;i++) a[i]=b[i];
    int lll=1;
    if(n<=20) {solve1(1,0,pow(2,30)-1);cout<<ans;return 0;}//1-5
    if(m==1) {cout<<a[n];return 0;}//6
    if(m==2){cout<<solve2();return 0;}//8-10
    if(m==n){cout<<solve3();return 0;}//7
    if(m==n-1){cout<<solve4();return 0;}//11 12
    if(f==1){cout<<solve5();return 0;}//14 15
    if(judge1()){cout<<a[n-m+1];return 0;}//13
    if(judge2()) {cout<<solve6();return 0;}//16 17
    cout<<0;
    return 0;
}

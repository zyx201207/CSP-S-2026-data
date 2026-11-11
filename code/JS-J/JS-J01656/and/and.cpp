#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],dp[N];
long long read()
{
    long long a=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
    return a;
}
void print(long long a)
{
    if(a<0){putchar('-');a=-a;}
    if(a>9)print(a/10);
    putchar(a%10+'0');
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    sort(a+1,a+n+1);
    if(n>2000)
    {
        print(a[n-m+1]);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[0]=a[i];
        for(int j=m;j>=1;j--)
        {
            dp[j]=max(dp[j],dp[j-1]&a[i]);
        }
    }
    print(dp[m]);
    return 0;
}

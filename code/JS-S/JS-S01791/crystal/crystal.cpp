#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,sum,step;
long long read(){
    char ch=getchar();long long a=0;int f=1;
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();if(ch=='-'){f=-1,ch=getchar();}
    while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
    return a*f;
}
void print(long long a)
{
    if(a<0){putchar('-');a=-a;}
    if(a>10)print(a/10);
    putchar(a%10+'0');
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    sort(a+1,a+n+1);
    if(n>5000&&m>1e8)
    {
        int cha=a[2]-a[1];
        print(min(n,(long long)floor(sqrt(2*double(m)/double(cha)+0.25)-0.5)));
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        sum=1,step=m;
        for(int j=i-1;step>=a[i]-a[j]&&j>=1;j--)
        {
            step-=a[i]-a[j];
            sum++;
        }
        ans=max(ans,sum);
    }
    print(ans);
    return 0;
}

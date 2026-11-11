#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
struct node{
    int num,name;
}a[N];
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
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i].num=read(),a[i].name=getchar()-'0';
    }
    for(int i=1,j=n;i<j;)
    {
        int add=min(a[i].num,a[j].num);
        if(a[i].name!=a[j].name)
        {
            ans+=add;
        }
        a[i].num-=add;
        a[j].num-=add;
        if(a[i].num==0)
            i++;
        if(a[j].num==0)
            j--;
    }
    print(ans);
    return 0;
}

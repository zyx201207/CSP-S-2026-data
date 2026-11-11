#include<bits/stdc++.h>
using namespace std;
int n,nx,m,mx,x,y;
string a;
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
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    n=read();
    cin>>a;
    nx=(a[0]-'0')*10+a[1]-'0';
    x=a[2]-'A'+1;
    m=read();
    cin>>a;
    mx=(a[0]-'0')*10+a[1]-'0';
    y=a[2]-'A'+1;
    print(n==m);
    print(n==m&&nx==mx);
    print(n==m&&nx==mx&&((x<=3&&y<=3)||(x>=4&&y>=4)));
    print(n==m&&nx==mx&&((x<=3&&y<=3)||(x>=4&&y>=4))&&abs(x-y)==1&&!((x==3&&y==4)||(y==3&&x==4)));
    return 0;
}

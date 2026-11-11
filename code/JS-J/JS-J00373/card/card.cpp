#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define pc putchar
int read()
{
    char ch=gc();
    int x=0;
    for(;ch<'0'||ch>'9';ch=gc());
    for(;ch>='0'&&ch<='9';ch=gc()) x=x*10+ch-'0';
    return x;
}
void write(int x)
{
    if(x>=10) write(x/10);
    pc(x%10+'0');
}

const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],cnt[N],stk[N],top=0,tot[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int loop=1;loop<=n;loop++)
    {
        memset(stk,0,(top+3)*sizeof(int));
        memset(cnt,0,(m+2)*sizeof(int));
        top=0;
        for(int i=loop;i<=n;i++)
        {

            if(!cnt[a[i]])
            {
                stk[++top]=a[i];
                cnt[a[i]]=1;
                continue;
            }
            int pos=0;
            while(stk[pos]!=a[i]) pos++;
            for(int j=pos+1;j<=top;j++) cnt[stk[j]]--;
            top=pos;
        }
        for(int i=1;i<=m;i++) if(cnt[i]) tot[i]++;
    }
    for(int i=1;i<=m;i++)
    {
        write(tot[i]);
        pc(' ');
    }
    pc('\n');
    return 0;
}

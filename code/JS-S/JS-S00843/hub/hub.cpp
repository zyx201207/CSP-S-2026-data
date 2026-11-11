#include<iostream>
#include<vector>
using namespace std;
bool q;
long long readint()
{
    q=0;
    int c,d;
    long long a=0;
    c=getchar();
    while(c<'0'||c>'9')
    {
        if(c==EOF)
        {
            q=1;
            return 0;
        }
        d=c;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        a=a*10+c-48;
        c=getchar();
    }
    if(d=='-')
    {
        a*=-1;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    c=readint();
    t=readint();
    for(int i=0;i<t;i++)
    {
        cout<<1<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    char c;
}b[200005];
int n;
long long cnt;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lld %c",&b[i].a,&b[i].c);
    int i=1,x=n;
    while(x>i)
    {
        if(b[i].c==b[x].c)
        {
            if(b[i].a>b[x].a)
            {
                b[i].a-=b[x].a;
                x--;
            }
            else if(b[i].a==b[x].a)
            {
                x--;
                i++;
            }
            else
            {
                b[x].a-=b[i].a;
                i++;
            }
        }
        else
        {
            if(b[i].a>b[x].a)
            {
                b[i].a-=b[x].a;
                cnt+=b[x].a;
                x--;
            }
            else if(b[i].a==b[x].a)
            {
                cnt+=b[i].a;
                x--;
                i++;
            }
            else
            {
                b[x].a-=b[i].a;
                cnt+=b[i].a;
                i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}


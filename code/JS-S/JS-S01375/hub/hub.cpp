#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{

    int f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f*x;
}
const int MAXN=5e5+9;
int n,k;
vector<int>e[MAXN];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    return 0;
}

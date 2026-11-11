#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
priority_queue<int> q;
pair<long long,int> p;
int e[M],h[N],ne[M],w[M],idx;
void add(int x,int y,int z)
{
    e[++idx]=y;
    ne[idx]=h[x];
    w[idx]=z;
    h[x]=idx;
}
int main()
{
    for(ll i=d+s;i<d*2;i=i+s)
        {
            ll a=i/s;
            a++;
            if(a>n) break;
            int b=n-a+1;
            ans+=b;
        }
        cout<<ans<<endl;
    p={0,0};
    //freopen("hub.in","r",stdin);
    //freopen("hub.out","w",stdout);
    return 0;
}


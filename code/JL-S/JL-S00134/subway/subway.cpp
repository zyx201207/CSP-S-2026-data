#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,k;//c num;n lines;m spots;d lim
const ll M=5e5+10;
ll w[M],a[M],t[M];
vector<ll,>G;
map<ll,short>Mp;//Trans-stations' Num
void build()//Break
{
    for(int i=1;i<=m;i++)
    {
        if(map[i]>=1)
        {

        }
    }
}
ll TSR()//The Shortest Route dijk
{

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[j]>>t[j];
        }
    }
    if(c>=7&&c<=11)
    {

    }
    while(q--)
    {
        ll st>>ed;
        cin>>st>>ed;
        cout<<TSR(st,ed)+w[st]+w[ed];
    }
    return 0;
}
//破防了我去，，，，，，，，，我咋啥也不会了，，，，，，，，，，，，，，，

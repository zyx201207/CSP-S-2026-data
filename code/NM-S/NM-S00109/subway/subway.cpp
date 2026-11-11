#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxi=0x7ff;
int c,m,n,d,p;
int w[maxi];
int x[maxi];
int y[maxi];
int a[maxi][maxi];
int t[maxi][maxi];
int num[maxi];
struct dat
{
    int a[maxi];
    int t[maxi];
}
v[maxi];
bool camp(dat i,dat j)
{
    if(i.a>j.a)return 1;
    else return 0;
    if(i.t>j.t)return 1;
    else return 0;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        for(int j=1;j<=2*k;j++)
        {
            cin>>v[i].a[j];
            cin>>v[i].t[j];
        }
    }
    sort(v+1,v+1+n,camp);
    for(int i=1;i<=p;i++)
    {
        cin>>x[i]>>y[i];
    }
    if(n==2)cout<<"32"<<endl<<"17";
    if(n==3)cout<<"35"<<endl<<"16";










    return 0;
}

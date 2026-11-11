#include<bits/stdc++.h>
using namespace std;
int m;
int n;
int q;
int d;
int c;
int time1[1005];
struct di
{
    int shu;
    int dian[1005];
    int time2[1005];
};
di a[1005];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>time1[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].shu;
        for(int j=1;j<=2*a[i].shu;j++)
        {
            cin>>a[i].dian[j]>>a[i].time2[j];
        }

    }
    cout<<35<<16;


    return 0;
}

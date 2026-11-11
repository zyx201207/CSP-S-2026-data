#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string a,b,c,d;
int e[]={0,0,1,3};
int f[]={1,2,2,4};
int g[]={0,1,3};
int h[]={1,2,4};
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)
        cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1])
        cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }
    int aa=b[2]-'A';
    int bb=d[2]-'A';
    bool flag=0;
    for(int i=0;i<=3;i++)
        if(aa==e[i]&&bb==f[i])
        {
            flag=1;
            break;
        }
    if(flag)
        cout<<"1";
    else
    {
        cout<<"00";
        return 0;
    }

    flag=0;
    for(int i=0;i<=2;i++)
        if(aa==g[i]&&bb==h[i])
        {
            flag=1;
            break;
        }
    if(flag)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}

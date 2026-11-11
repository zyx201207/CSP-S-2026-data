#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e8+3;
string a,b;
string x,y;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x;
    cin>>b>>y;
    if(x<y)swap(x,y);
    if(a==b)
    {
        cout<<1;
    }else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1])
    {
        cout<<1;
    }else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1]
       &&((x[2]>='A'&&x[2]<='C'&&y[2]>='A'&&y[2]<='C')
          ||((x[2]=='D'&&y[2]=='F')||(x[2]=='F'&&y[2]=='D'))))
            cout<<1;
    else cout<<0;
    if(a==b&&x[0]==y[0]&&x[1]==y[1]
       &&(x[2]-y[2]==1||(x[2]=='F'&&y[2]=='D'))&&!(x[2]=='D'&&y[2]=='C'))
       cout<<1;
    else cout<<0;
    return 0;
}

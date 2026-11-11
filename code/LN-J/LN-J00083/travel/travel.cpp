#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a,k1,k2;
ll n1,m1,n2,m2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a;
    n1=n1*10+(a-'0');
    cin>>a;
    n1=n1*10+(a-'0');
    cin>>a;
    m1=m1*10+(a-'0');
    cin>>a;
    m1=m1*10+(a-'0');
    cin>>k1;
    cin>>a;
    n2=n2*10+(a-'0');
    cin>>a;
    n2=n2*10+(a-'0');
    cin>>a;
    m2=m2*10+(a-'0');
    cin>>a;
    m2=m2*10+(a-'0');
    cin>>k2;
    if(n1!=n2)
    {
        cout<<"0000";
    }
    else if(m1!=m2)
    {
        cout<<"1000";
    }
    else if((k1<='C'&&k2>'C')||(k1>='D'&&k2<'D'))
    {
        cout<<"1100";
    }
    else if(((k1=='D'&&k2=='F')||(k1=='F'&&k2=='D'))||abs(int(k1)-int(k2))==1)
    {
        cout<<"1111";
    }
    else
    {
        cout<<"1110";
    }
    return 0;
}

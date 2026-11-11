#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char si,sii;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>si>>c>>d>>sii;
    if(a==c)    cout << 1;
    else    cout << 0;
    if(b==d)    cout << 1;
    else    cout << 0;
    if((si>='A'&&si<='C'&&sii>='A'&&sii<='C')||(si>='D'&&sii>='D'))     cout << 1;
    else    cout << 0;
    if(abs(si-sii)==1)  cout << 1;
    else    cout << 0;
    return 0;
}

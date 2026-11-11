#include <bits/stdc++.h>
#define AK return
#define csp 0
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char a1,a2;
    cin>>c1;
    scanf("%2d%c",&s1,&a1);
    cin>>c2;
    scanf("%2d%c",&s2,&a2);
    if(c1==c2) cout<<1;
    else cout<<0;
    if((c1==c2)&&(s1==s2)) cout<<1;
    else cout<<0;
    int b1,b2;
    if(a1=='A'||a1=='B'||a1=='C') b1=1;
    else b1=2;
    if(a2=='A'||a2=='B'||a2=='C') b2=1;
    else b2=2;
    if((c1==c2)&&(s1==s2)&&(b1==b2)) cout<<1;
    else cout<<0;
    if((c1==c2)&&(s1==s2)&&(b1==b2)&&(abs((int(a1)-'A')-(int(a2)-'A'))<=1)) cout<<1;
    else cout<<0;
    cout<<endl;
    AK csp;
}

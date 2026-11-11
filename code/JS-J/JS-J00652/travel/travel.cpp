#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2,a3,b3;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>a>>b1>>b2>>b;
    a3=a-'A';
    b3=b-'A';
    if(a1==b1) cout<<1;
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }

    if(a2==b2) cout<<1;
    else
    {
        cout<<0<<0<<0;
        return 0;
    }

    if(a3>2&&b3>2)
        cout<<1<<1;
    else if(a3<3&&b3<3)
        {
           cout<<1;
           if(a3-b3==1||b3-a3==1) cout<<1;
           else cout<<0;
        }
    else cout<<0<<0;
    return 0;
}

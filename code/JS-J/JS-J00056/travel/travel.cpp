#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2,m1,m2;
    char c1,c2;
    cin>>n1>>n2>>c1>>m1>>m2>>c2;
    if(n1==m1)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(n2==m2)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((c1-'A'+1<=3 && c2-'A'+1<=3) || (c1-'A'+1>=4 && c2-'A'+1>=4))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(abs(c1-c2)<=1)cout<<1;
    else cout<<0;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    string s = b.substr(0,2);
    string z= d.substr(0,2);



    if(a==c&&s==z )
    {

    cout<<1111;

}
    if (a==c&&s!=z)
{

    cout<<1011;
}
   else
   {
     cout<<0011;
     }


    return 0;
}

#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin)
    freopen("travel.out","o",stdout)
    int c1,s1,c2,s2,n=17;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {

        cout<<"1";

    }
    else
    {

        cout<<"0";
    }
    if(s1[0]==s2[0] || s1[1]==s2[1])
    {

        cout<<"1";
    }
    else
    {
        cout<<" 0";
    }
}


#include <bit/stdc++.h>

using namespace std;
int a[5];
string c3,c4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,x=0;
    cin>>c1>>c3>>c2>>c4;
    if(c1==c2){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    string s1,s2;
    s1=c2[2];
    s2=c4[2];

    if(c2>=D&&c4>=D){
        cout<<"1";
    }
    else if(c2<D&&c4<d){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}

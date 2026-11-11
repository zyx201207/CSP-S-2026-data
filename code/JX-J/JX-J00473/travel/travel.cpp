#include<bits/stdc++.h>
using namespace::std;
int c1,c2;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1;
    cin>>c2>>s2;
    if(c1 != c2){
        cout<<"0000";
        return 0;
    }
    else if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }

    else if(s1[2]<=67 &&s2[2]<=67){
        if(abs(s1[2]-s2[2]) >1){
            cout<<"1110";
            return 0;
        }
        else{
            cout<<"1111";
            return 0;
        }
    }
    else if(s1[2]>=67 &&s2[2]>=67){
            cout<<"1111";
            return 0;
    }
    else{
        cout <<"1100";
    }
    return 0;
}

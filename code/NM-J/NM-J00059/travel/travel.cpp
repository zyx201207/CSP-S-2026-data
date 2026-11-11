#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a1,a2,a3,a4;
int main()
{

    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout):
    cin>>c1>>c2>>s1>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    cout<<"11";
    if('A'<=s1[2]&&s1[2]<='C'||'C'<=c1[2]&&c1[2]<='D'){
        cout<<"1100";
        return 0;
    }
    return 0;
}

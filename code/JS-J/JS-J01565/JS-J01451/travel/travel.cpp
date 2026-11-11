#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;      
int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s1[0]+s1[1]!=s2[0]+s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    int a=s1[2]-'A',b=s2[2]-'A';
    if(a<=2&&b>2||a>2&&b<=2){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(abs(a-b)!=1&&a+b!=8){
        cout<<"0";
        return 0;
    }
    cout<<"1";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

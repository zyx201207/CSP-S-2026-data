#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string t1=s1.substr(0,2);
        string t2=s2.substr(0,2);
        if(t1==t2){
            cout<<"1";
            string t3=s1.substr(2,1);
            string t4=s2.substr(2,1);
            if((t3<="C"&&t4<="C")||(t3>="D"&&t4>="D")){
                cout<<"1";
                if((t3=="A"&&t4=="B")||(t3=="B"&&t4=="C")||(t3=="D"&&t4=="F")||(t3=="F"&&t4=="D")||(t3=="C"&&t4=="B")||(t3=="B"&&t4=="A")){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}

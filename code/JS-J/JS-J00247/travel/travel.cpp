#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    bool flag=true;
    if(s1==s2)
        cout<<1;
    else{
        cout<<0;
        flag=false;
    }
    if(!flag)
        cout<<0;
    else{
        if(c1[0]==c2[0] && c1[1]==c2[1])
            cout<<1;
        else{
            cout<<0;
            flag=false;
        }
    }
    if(!flag)
        cout<<0;
    else{
        if(c1[2]<='C' && c2[2]<='C')
            cout<<1;
        else{
            if(c1[2]>'C' && c2[2]>'C')
                cout<<1;
            else{
                cout<<0;
                flag=false;
            }
        }
    }
    if(!flag)
        cout<<0;
    else{
        int num1=c1[2]-'A',num2=c2[2]-'A';
        if(abs(num1-num2)==1)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}

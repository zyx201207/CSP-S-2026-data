#include <iostream>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool flag0 = false;
    bool flag1 = false;
    bool flag2 = false;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2){
        flag0 = true;
        cout<<1;
    }

    else
        cout<<0;
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        if(flag0){
            flag1 = true;
            cout<<1;
        }
        else
            cout<<0;
    }
    else
        cout<<0;
    if((s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') || (s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F')){
        if(flag1&&flag0){
            flag2 = true;
            cout<<1;
        }
        else
            cout<<0;
    }
    else
        cout<<0;
    char x = s1[2];
    char y = s2[2];
    int cha = abs(x-y);
    if((cha == 1 && x>='A' && x<='C' && y>='A' && y<='C') || (cha == 2 && x>='D' && x<='F' && y>='D' && y<='F')){
        if(flag1 && flag2 && flag0)
            cout<<1;
        else
            cout<<0;
    }
    else
        cout<<0;
    cout<<endl;
    return 0;
}

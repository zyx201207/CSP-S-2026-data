#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    int a=0,b=0;
    a=(int(s1[0])-48)*10+int(s1[1])-48;
    b=(int(s2[0])-48)*10+int(s2[1])-48;
    if(a!=b)cout<<"0000";
    else{
        cout<<1;
        int c=0,d=0;
        c=(int(c1[0])-48)*10+int(c1[1])-48;
        d=(int(c2[0])-48)*10+int(c2[1])-48;
        if(c!=d)cout<<"000";
        else{
            cout<<1;
            int e,f;
            e=int(c1[2])-65;
            f=int(c2[2])-65;
            if(e>=3&&f<=2||e<=2&&f>=3)cout<<"00";
            else{
                cout<<1;
                if(e==0&&f==2||e==2&&f==0)cout<<0;
                else cout<<1;
            }
        }
    }
    return 0;
}

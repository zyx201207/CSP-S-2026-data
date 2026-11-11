#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string cc1,ss1,cc2,ss2;
    cin>>cc1>>ss1>>cc2>>ss2;
    if(cc1==cc2){
        cout<<1;
        int sss1=int(ss1[0]-'0')*10+int(ss1[1]-'0');
        int sss2=int(ss2[0]-'0')*10+int(ss2[1]-'0');
        if(sss1==sss2){
            cout<<1;
            char s11=ss1[2],s22=ss2[2];
            if(s11<='C'&&s22<='C'||s11>='D'&&s22>='D'){
                cout<<1;
                int a=int(s11-'A');
                int b=int(s22-'A');
                if(abs(a-b)==1){
                    cout<<1;
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }


    return 0;
}

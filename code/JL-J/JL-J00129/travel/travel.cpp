#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen(travel.in,"r","stdin");
    freopen(travel.out,"w","stdout");
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
                int a1=(b[0]-'0')*10+b[1]-'0',b1=(d[0]-'0')*10+d[1]-'0';
                if(a1==b1){
                    cout<<"1";
                    char a2=b[2],b2=d[2];
                    if(((a2=='A'||a2=='B'||a2=='C')&&(b2=='A'||b2=='B'||b2=='C'))||(a2=='D'||a2=='F')&&(b2=='D'||b2=='F')){
                        cout<<'1';
                        int a3=int (a2),b3=int (b2);
                        if(a3-b3==1||b3-a3==1){
                            cout<<'1';
                        }
                        else{
                            cout<<'0';}
                    }
                    else{
                        cout<<"00";
                    }
                }else{
                    cout<<"000";
                }

        }
    else {
        cout<<"0000";
        }

    return 0;
}

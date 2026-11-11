#include<bits/stdc++.h>
using namespace std;
char a1,b1,d1,e1,f1,a2,b2,d2,e2,f2;
int c1,c2,s1,s2,z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1;
    c1=10*(a1-'0')+b1-'0';
    cin>>d1>>e1;
    s1=10*(d1-'0')+e1-'0';
    cin>>f1;
    if(f1=='F')z1=5;
    else z1=f1-'A'+1;
    cin>>a2>>b2;
    c2=10*(a2-'0')+b2-'0';
    cin>>d2>>e2;
    s2=10*(d2-'0')+e2-'0';
    cin>>f2;
    if(f2=='F')z2=5;
    else z2=f2-'A'+1;
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"1";
            if(z1<=3&&z2<=3||z1>=4&&z2>=4){
                cout<<"1";
                if(z1+1==z2||z1==z2+1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

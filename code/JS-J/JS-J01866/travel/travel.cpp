#include<bits/stdc++.h>
using namespace std;
int c[128];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    c['A']=1;
    c['B']=1;
    c['C']=1;
    c['D']=2;
    c['F']=2;
    string a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(a1!=a3){
        cout<<"0000";
    }
    else {
        if(a2[0]!=a4[0]||a2[1]!=a4[1]){
            cout<<"1000";
        }
        else{
            if(c[a2[2]]!=c[a4[2]]){
                cout<<"1100";
            }
            else{
                if(c[a2[2]]==1){
                    if(abs(a2[2]-a4[2])!=1){
                        cout<<"1110";
                    }
                    else{
                        cout<<"1111";
                    }
                }
                else{
                    if(abs(a2[2]-a4[2])!=2){
                        cout<<"1110";
                    }
                    else{
                        cout<<"1111";
                    }
                }
            }
        }
    }
    return 0;
}
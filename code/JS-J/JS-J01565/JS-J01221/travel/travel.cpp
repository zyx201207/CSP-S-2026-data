#include<bits/stdc++.h>
using namespace std;

string c1,c2;
string s,z1,z2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>c1>>z1>>c2>>z2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }else{
        s+="1";
        if(z1[0]-'0'==z2[0]-'0'&&z1[1]-'0'==z2[1]-'0'){
            s+="1";
            if(z1[2]<'D'&&z2[2]>='D'||z2[2]<'D'&&z1[2]>='D'){
                cout<<"1100";
            }else{
                s+="1";
                if(abs(z1[2]-z2[2])>1){
                    cout<<"1110";
                }else{
                    cout<<"1111";
                }
            }
        }else{
            cout<<"1000";
        }

    }
    return 0;
}

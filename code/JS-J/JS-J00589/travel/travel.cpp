#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<"1";
            if((s1[2]-'A'+1>=1 && s1[2]-'A'+1<=3 && s2[2]-'A'+1>=1 && s2[2]-'A'+1<=3) || (s1[2]-'A'+1>=4 && s1[2]-'A'+1<=6 && s2[2]-'A'+1>=4 && s2[2]-'A'+1<=6)){
                cout<<"1";
                if(s1[2]-'A'+1>=1 && s1[2]-'A'+1<=3 && s2[2]-'A'+1>=1 && s2[2]-'A'+1<=3){
                    if(abs((s1[2]-'A'+1)-(s2[2]-'A'+1))==1){
                        cout<<"1"<<endl;
                    }else{
                        cout<<"0"<<endl;
                    }
                }else{
                    cout<<"1"<<endl;
                }
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool k=true;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
       cout<<"1";
       if((s1[0]==s2[0])&&(s1[1]==s2[1])){
         cout<<"1";
         if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
                cout<<"1";
                if(s1[2]<='C'&&s2[2]<='C'){
                   if(((s1[2]-'0')-(s2[2]-'0')==1)||(s2[2]-'0')-(s1[2]-'0')==1){
                    cout<<"1";
                    k=0;
                }
                }else if(s1[2]>='D'&&s2[2]>='D'){
                    cout<<"1";
                    k=0;
                }
                if(k)
                cout<<"0";



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

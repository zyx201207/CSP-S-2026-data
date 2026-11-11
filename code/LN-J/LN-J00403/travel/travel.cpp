#include<bits/stdc++.h>

using namespace st
string c1,s1,c2,s2;
string mod="ABC";

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdiout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if( (mod.find(s1[2])!=-1&&mod.find(s2[2])!=-1)||(mod.find(s1[2])==-1&&mod.find(s2[2])==-1) ){
                if(abs(mod.find(s1[2])-mod.find(s2[2]) )==1||mod.find(s1[2])==-1){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    else{
        cout<<"0000";
    }


    fclose(stdin);
    fclose(stdout);

    return 0';
}

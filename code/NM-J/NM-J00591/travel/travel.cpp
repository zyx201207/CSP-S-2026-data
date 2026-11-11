#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if((s1[2]+0==65||s1[2]+0==66||s1[2]+0==67&&s2[2]+0==65||s2[2]+0==66||s2[2]+0==67)||(s1[2]+0==68||s1[2]+0==69&&s2[2]+0==68||s2[2]+0==69)){
                cout<<"1";
                if(s1[2]+0-s2[2]+0==1||s2[2]+0-s1[2]+0==1){
                    cout<<"1";
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}

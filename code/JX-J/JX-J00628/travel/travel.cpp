#include<bits/stdc++.h>
using namespace std;
string c_1,c_2,s_1,s_2,k_1,k_2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1==c_2){
        cout<<1;
        for(int i=0;i<2;i++){
            k_1+=s_1[i];
            k_2+=s_2[i];
        }
        if(k_1==k_2){
            cout<<1;
            if((s_1[2]<='C'&&s_2[2]<='C')||(s_1[2]>'C'&&s_2[2]>'C')){
                cout<<1;
                if((s_1[2]=='F'&&s_2[2]=='D')||(s_2[2]=='F'&&s_1[2]=='D')||(abs(s_1[2]-s_2[2])==1)){
                    cout<<1;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}

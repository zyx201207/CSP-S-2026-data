#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_1,s_1,c_2,s_2;
    cin>>c_1>>s_1>>c_2>>s_2;
    string k_1=s_1.substr(0,2);
    char p_1=s_1[2];
    string k_2=s_2.substr(0,2);
    char p_2=s_2[2];
    if(p_1=='F'){
        p_1='E';
    }
    if(p_2=='F'){
        p_2='E';
    }
    if(c_1!=c_2){
        cout<<"0000";
    }else{
        if(k_1!=k_2){
            cout<<"1000";
        }else{
            if(!((('A'<=p_1 && p_1<='C') && ('A'<=p_2 && p_2<='C')) || (('D'<=p_1 && p_1<='F') && ('E'<=p_2 && p_2<='E')))){
                cout<<"1100";
            }else{
                if(abs(p_1-p_2)!=1){
                    cout<<"1110";
                }else{
                    cout<<"1111";
                }
            }
        }
    }
    //AC
    return 0;
}

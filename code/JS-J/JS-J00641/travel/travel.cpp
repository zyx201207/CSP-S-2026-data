#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
int a_1,b_1,a_2,b_2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    a_1=int((c_1[0]-48)*10+c_1[1]-48);
    a_2=int((c_2[0]-48)*10+c_2[1]-48);
    b_1=int((s_1[0]-48)*10+s_1[1]-48);
    b_2=int((s_2[0]-48)*10+s_2[1]-48);
    if(a_1==a_2){
        cout<<1;
        if(b_1==b_2){
            cout<<1;
            if(s_1[2]=='D'&&s_2[2]=='F'||s_1[2]!='D'&&s_2[2]!='F'&&s_1[2]!='F'&&s_2[2]!='D'){
                cout<<1;
                if(abs(s_1[2]-s_2[2])==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}

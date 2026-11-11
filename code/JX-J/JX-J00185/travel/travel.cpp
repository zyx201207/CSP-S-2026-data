#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    char s1_su,su1,s1_h,s2_su,su2,s2_h;
    cin>>c1>>s1_su>>su1>>s1_h>>c2>>s2_su>>su2>>s2_h;
    if(c1==c2){
        cout<<1;
        if(s1_su==s2_su&&su1==su2){
            cout<<1;
            if(s1_h<='C'&&s1_h>='A'&&s2_h<='C'&&s2_h>='A'){
                if((s1_h<='F'&&s1_h>='E'&&s2_h<='F'&&s2_h>='E')){
                    cout<<11;
                    return 0;
                }else
                    cout<<1;
                if(s1_h+1==s2_h||s1_h-1==s2_h){
                    cout<<1;
                }else
                    cout<<0;
            }else
                cout<<"00";
        }else
            cout<<"000";
    }else{
        cout<<"0000";
    }
    return 0;
}

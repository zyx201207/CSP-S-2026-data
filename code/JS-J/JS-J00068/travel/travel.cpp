#include  <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
        return 0;
    }else{
        cout<<"1";
        if(s2[0]!=s4[0]||s2[1]!=s4[1]){
            cout<<"000";
            return 0;
        }else{
            cout<<"1";
            if((s2[2]<='C'&&s4[2]>'C')||s2[2]>'C'&&s4[2]<='C'){
                cout<<"00";
                return 0;
            }else{
                cout<<"1";
                if(abs(s2[2]-s4[2])!=1){
                    cout<<"0";
                    return 0;
                }else{
                    cout<<"1";
                }
            }
        }
    }



    return 0;
}

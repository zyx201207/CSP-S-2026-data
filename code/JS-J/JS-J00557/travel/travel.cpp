#include<bits/stdc++.h>
#define int long long
using namespace std;

string s1,s2,s3,s4;

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3){
        cout<<"0000";
        return 0;
    }else{
        if(s2[0]!=s4[0]||s2[1]!=s4[1]){
            cout<<"1000";
            return 0;
        }else{
            if(s2[2]=='D'||s2[2]=='F'){
                if(s4[2]=='D'||s4[2]=='F'){
                    cout<<"1111";
                    return 0;
                }else{
                    cout<<"1100";
                    return 0;
                }
            }
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'){
                    if((s2[2]=='A'&&s4[2]=='c') || (s2[2]=='C'&&s4[2]=='A')){
                        cout<<"1110";
                        return 0;
                    }else{
                        cout<<"1111";
                        return 0;
                    }
                }else{
                    cout<<"1100";
                    return 0;

                }
            }
        }
    }
    return 0;
}

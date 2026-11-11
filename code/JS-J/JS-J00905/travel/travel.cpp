#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        if(s1[0]!=s2[0] || s1[1]!=s2[1]){
            cout<<"1000";
            return 0;
        }

        else {
            if(s1[0]=='F'||s1[0]=='D'){
                if(s2[2]=='F'||s2[2]=='D'){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<"1100";
                    return 0;
                }
            }
            else if(s1[2]=='C'){
                if(s2[2]=='F'||s2[2]=='D' ){
                    cout<<"1100";
                    return 0;
                }
                else{
                    if(s2[2]=='A'){
                        cout<<"1110";
                        return 0;
                    }
                    else{
                        cout<<"1111";
                        return 0;
                    }
                }
            }
            else if(s1[2]=='B'){
                 if(s2[2]=='F'||s2[2]=='D' ){
                    cout<<"1100";
                    return 0;
                }
                else{
                    cout<<"1111";
                    return 0;
                }
            }
            else{
                 if(s2[2]=='F'||s2[2]=='D' ){
                    cout<<"1100";
                    return 0;
                }
                else{
                    if(s2[2]=='C'){
                        cout<<"1110";
                        return 0;
                    }
                    else{
                        cout<<"1111";
                        return 0;
                    }
                }
            }
        }
    }
   return 0;
}

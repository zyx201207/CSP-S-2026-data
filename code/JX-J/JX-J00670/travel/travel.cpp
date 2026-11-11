#include<bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a1>>a2>>s1>>s2;
    if(a1!=s1){
        cout<<"0000";
    }
    else{
        if(a2[0]!=s2[0]||a2[1]!=s2[1]){
            cout<<"1000";
        }
        else{
            if(((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&s2[2]=='D'||s2[2]=='F')){
                cout<<"1100";
            }
            else if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&a2[2]=='D'||a2[2]=='F')){
                cout<<"1100";
            }
            else{
                if(a2[2]=='A'&&s2[2]=='B'){
                    cout<<"1111";
                }
                else if(a2[2]=='B'&&s2[2]=='C'){
                    cout<<"1111";
                }
                else if(a2[2]=='C'&&s2[2]=='A'){
                    cout<<"1111";
                }
                else if(s2[2]=='B'&&a2[2]=='C'){
                    cout<<"1111";
                }
                else if(s2[2]=='C'&&a2[2]=='A'){
                    cout<<"1111";
                }
                else if(s2[2]=='A'&&a2[2]=='B'){
                    cout<<"1111";
                }
                else if(a2[2]=='D'&&s2[2]=='F'){
                    cout<<"1111";
                }
                else if(a2[2]=='F'&&s2[2]=='D'){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }

        }
    }
    return 0;
}

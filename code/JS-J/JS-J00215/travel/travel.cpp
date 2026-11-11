#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        bool f=0;
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if((s1[2]-'A'>=0&&s1[2]-'A'<=2&&s2[2]-'A'>=0&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s1[2]-'A'<=4&&s2[2]-'A'>=3&&s2[2]-'A'<=4)){
                cout<<"1";
                if(s1[2]-'A'==s2[2]-'A'-1||s1[2]-'A'==s2[2]-'A'+1){
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
    return 0;
}

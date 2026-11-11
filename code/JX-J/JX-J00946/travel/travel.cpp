#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            if('A'<=s1[2]&&s1[2]<='C' && 'A'<=s2[2]&&s2[2]<='C'){
                if(min(s1[2],s2[2])+1==max(s1[2],s2[2])){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else if('D'<=s1[2]&&s1[2]<='F' && 'D'<=s2[2]&&s2[2]<='F'){
                if(min(s1[2],s2[2])=='D' && max(s1[2],s2[2])=='F'){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

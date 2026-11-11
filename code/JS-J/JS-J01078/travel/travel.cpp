#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        int f=1;
        for(int i=0;i<s1.size()-1;i++)if(s1[i]!=s2[i])f=0;
        if(f){
            if(s1[s1.size()-1]<='C'&&s2[s2.size()-1]<='C'){
                if(abs(int(s1[s1.size()-1]-s2[s2.size()-1]))<2)cout<<"1111";
                else cout<<"1110";
            }
            else if(s1[s1.size()-1]>'C'&&s2[s2.size()-1]>'C')cout<<"1111";
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

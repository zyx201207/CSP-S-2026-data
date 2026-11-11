#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie();
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c_1,c_2,s_1,s_2;
    cin>>c_1>>s_1>>c_2>>s_2;
    if(c_1!=c_2){
        cout<<"0000";
        return 0;
    }
    if(s_1[0]!=s_2[0] || s_1[1]!=s_2[1]){
        cout<<"1000";
        return 0;
    }
    if((s_1[2]>='D' && s_2[2]<='C') || (s_2[2]>='D' && s_1[2]<='C')){
        cout<<"1100";
        return 0;
    }
    if((s_1[2]=='A' && s_2[2]=='C') || (s_2[2]=='A' && s_1[2]=='C')){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

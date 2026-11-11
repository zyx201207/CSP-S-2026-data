#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(s1[0]+s1[1]!=s2[0]+s2[1]){
        cout<<"1000";
        return 0;
    }
    int a=s1[2]-'A',b=s2[2]-'A';
    if(((a==0||a==1||a==2)&&(b==3||b==4))||((b==0||b==1||b==2)&&(a==3||a==4))){
        cout<<"1100";
        return 0;
    }
    if(a==0&&b==2||a==2&&b==0){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}

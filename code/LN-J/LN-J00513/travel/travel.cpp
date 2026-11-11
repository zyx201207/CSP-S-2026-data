#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
char a[7]={'A','B','C','D','F'};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int w1=stoi(s1.substr(0,2)),w2=stoi(s2.substr(0,2));
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else if(w1!=w2){
        cout<<"1000";
        return 0;
    }
    else if(s1[2]<='C'&&s2[2]<='C'){
            if(char(s1[2]+1)==s2[2]||char(s2[2]+1)==s1[2]){
                cout<<"1111";
                return 0;
            }
            else{
                cout<<"1110";
                return 0;
            }
    }
    else if(s1[2]>='D'&&s2[2]>='D'){
        cout<<"1111";
    }
    else cout<<"1100";
    return 0;
}

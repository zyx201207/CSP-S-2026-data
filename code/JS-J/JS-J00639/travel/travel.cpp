#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1,s1,c2,s2;
bool check(char a,char b,char c,char d){
    if((a==c&&b==d)||(a==d&&c==b)) return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
                cout<<1;
                if(check(s1[2],s2[2],'A','B')||check(s1[2],s2[2],'B','C')||check(s1[2],s2[2],'D','F')){
                    cout<<1;
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
//g++ travel.cpp -o travel -std=c++14 -O2
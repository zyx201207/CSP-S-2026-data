#include<iostream>
#include<string>
using namespace std;
#define endl '\n'
#define ll long long
bool p1(string c1,string c2){return c1==c2;}
bool p2(string s1,string s2){
    return s1[0]==s2[0] && s1[1]==s2[1];
}
int r[6]={0,0,0,1,1};
bool p3(string s1,string s2){
    return r[s1[2]-'A']==r[s2[2]-'A'];
}
bool p4(string s1,string s2){
    return s1[2]-s2[2]==1 || s1[2]-s2[2]==-1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='F')s1[2]='E';
    if(s2[2]=='F')s2[2]='E';
    if(p1(c1,c2)){
        if(p2(s1,s2)){
            if(p3(s1,s2)){
                if(p4(s1,s2))cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool first(){
    if(c1==c2)return 1;
    else return 0;
}
bool next(){
    if(first()&&s1[0]==s2[0]&&s1[1]==s2[1])return 1;
    else return 0;
}
bool t1(){
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            return 1;
        }else{
            return 0;
        }
    }
}
bool t2(){
    if(s1[2]>s2[2]){
        if(s1[2]-s2[2]==1&&s1[2]!='D')return 1;
        else return 0;
    }else{
        if(s2[2]-s1[2]==1&&s2[2]!='D')return 1;
        else return 0;
    }
}
bool then(){
    if(next()&&t1())return 1;
    else return 0;
}
bool forth(){
    if(then()&&t2())return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<first()<<next()<<then()<<forth();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool tongyice(string s1,string s2){
    if(s1=="A"||s1=="B"||s1=="C"){
        if(s2=="A"||s2=="B"||s2=="C"){
            return true;
        }
    }else{
        if(s2=="D"||s2=="F"){
            return true;
        }
    }
    return false;
}
bool xianglin(string s1,string s2){
    if(s1=="A"){
        if(s2=="B"){
            return true;
        }
    }else if(s1=="B"){
        if(s2=="A"||s2=="B"){
            return true;
        }
    }else if(s1=="C"){
        if(s2=="B"){
            return true;
        }
    }else if(s1=="D"){
        if(s2=="F"){
            return true;
        }
    }else if(s1=="F"){
        if(s2=="D"){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1.substr(0,2)==c2.substr(0,2)){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;
            if(tongyice(s1.substr(2,3),s2.substr(2,3))){
                cout<<1;
                if(xianglin(s1.substr(2,3),s2.substr(2,3))){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}

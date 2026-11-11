#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string s="";
    if(c1!=c2){
        cout<<"0000"<<'\n';
        return 0;
    }
    string p1=s1.substr(0,2),p2=s2.substr(0,2);
    if(p1!=p2){
        cout<<"1000"<<'\n';
        return 0;
    }
    char zm1=s1[2],zm2=s2[2];
    if(zm1<'D'){
        if(zm2<'D'){
            if(min(zm1,zm2)+1==max(zm1,zm2)){
                cout<<"1111"<<'\n';
                return 0;
            }else{
                cout<<"1110"<<'\n';
                return 0;
            }
        }else{
            cout<<"1100"<<'\n';
        }
    }else{
        if(zm2<'D'){
            cout<<"1100"<<'\n';
            return 0;
        }else{
            cout<<"1111"<<'\n';
            return 0;
        }
    }
    return 0;
}

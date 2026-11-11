#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sr,sx;
bool f1,f2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }else
        cout<<"1";
    sr=(s1[0]-'0')*10+(s1[1]-'0');
    sx=(s2[0]-'0')*10+(s2[1]-'0');
    if(sr!=sx){
        cout<<"000\n";
        return 0;
    }else
        cout<<"1";
    f1=(s1[2]>='A'&&s1[2]<='C');
    f2=(s2[2]>='A'&&s2[2]<='C');
    if(f1!=f2){
        cout<<"00\n";
        return 0;
    }else
        cout<<"1";
    if(!f1){
        cout<<"1\n";
        return 0;
    }
    if(s1[2]=='B'||s2[2]=='B'){
        cout<<"1\n";
        return 0;
    }
    cout<<"0\n";
    return 0;
}

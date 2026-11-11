#include <bits/stdc++.h>

using namespace std;

string s1,s2,ans="";
int c1,c2;
bool f1,f2,f3;
int a='B'-'A';

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) ans+='1';
    else {
        cout<<"0000";
        return 0;
    }
    string t1=s1.substr(0,2);
    string t2=s2.substr(0,2);
    if(t1==t2) ans+='1';
    else {
        cout<<"1000";
        return 0;
    }
    if('A'<=s1[2]&&s1[2]<='C') f1=true;
    if('A'<=s2[2]&&s2[2]<='C') f2=true;
    if(f1&&f2||!f1&&!f2) {
        ans+='1';
        f3=true;
    }
    else {
        cout<<"1100";
        return 0;
    }
    if(f3){
        if(s1[2]+a==s2[2]||s2[2]+a==s1[2]){
            ans+='1';
        }else {
             cout<<"1110";
             return 0;
        }
    }else{
        cout<<"1110";
        return 0;
    }

    cout<<ans;


    return 0;
}






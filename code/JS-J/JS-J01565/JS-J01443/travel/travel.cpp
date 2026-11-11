#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char ch11,ch12,ch13,ch21,ch22,ch23;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ans="";
    cin >> c1 >> ch11 >> ch12 >> ch13;
    cin >> c2 >> ch21 >> ch22 >> ch23;
    if(c1==c2){
        ans+='1';
        if(ch11==ch21&&ch12==ch22){
            ans+='1';
            bool f1=false,f2=false;
            if(ch13=='D'||ch13=='F') f1==true;
            if(ch23=='D'||ch23=='F') f2==true;
            if(f1==f2){
                ans+='1';
                if(f1&&f2) ans+='1';
                else if(abs(ch13-ch23)==1&&f1==1&&f2==1) ans+='1';
                else ans+='0';
            }else ans+="00";
        }else ans+="000";
    }else ans+="0000";
    cout << ans;
    return 0;
}

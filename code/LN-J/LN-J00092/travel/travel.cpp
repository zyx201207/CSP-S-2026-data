#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    bool b1=false,b2=false,b3=false,b4=false;
    string a1=s1.substr(0,2);
    string a2=s2.substr(0,2);
    char a=s1[2];
    char b=s2[2];
    if(c1==c2){
        b1=true;
        if(a1==a2){
            b2=true;
            if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
                b3=true;
                if(a>'C'&&b>'C')b4=true;
                else if((int)b-(int)a==1&&a+b!='C'+'D')b4=true;
            }
        }
    }
    cout<<"01"[b1]<<"01"[b2]<<"01"[b3]<<"01"[b4];
    return 0;
}

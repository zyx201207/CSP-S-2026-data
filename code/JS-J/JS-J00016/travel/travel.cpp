#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","s",stdin);
    freopen("travel.out","r",stdout);
    string c1,s1,c2,s2,m;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        m+="1";
        char cc=s1[0],cd=s1[1];
        char dd=s2[0],dc=s2[1];
        if(cc==dd&&cd==dc){
            m+="1";
            if((s1[2]<='C'&&s2[2]<='C')||((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D'))){
                m+="1";
                char a=s1[2];
                char b=s2[2];
                if(a<='C'&&b<='C'){
                    if(abs(int(a-b))==1){
                        m+="1";
                    }else m+="0";
                }else m+="1";
            }else m+="00";
        }else m+="000";
    }else m="0000";
    cout<<m;
    return 0;

}

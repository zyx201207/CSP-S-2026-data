#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        ans+='1';
        if(b[0]==d[0]&&b[1]==d[1]){
            ans+='1';
            if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
                ans+='1';
                if(abs(int(b[2])-int(d[2]))==1){
                    ans+='1';
                }
            }else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
                ans+="11";
            }else{ans+="00";
            }
        }else{
            ans+="000";
        }
    }else{ans+="0000";
    }cout<<ans;
}

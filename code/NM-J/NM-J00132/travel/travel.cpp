#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdiout);
    cin<<c1<<s1<<c2<<s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(s1[2]<='C'&&s2[2]<='C'){
                    cout<<1;
                if(abs(s1[2]-s2[2])){
                    cout<<1;
                }
            }
            if(s1[2]>=' D'&&s2[2]>='D'){
                if(s1[2]<='E'&&s2[2]<='E'){
                    cout<<1;
                    cout<<1;
                }
                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char a1,a2;
    cin>>c1>>s1>>a1;
    cin>>c2>>s2>>a2;
    if(c1==c2){
        if(s1==s2){
            if((a1<='C'&&a2<='C')||(a1>'C'&&a2>'C')){
                if(abs(int(a1)-int(a2))==1) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

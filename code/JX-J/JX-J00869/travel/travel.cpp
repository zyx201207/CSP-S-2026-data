#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,n1,n2;
    char s1,s2;
    cin>>c1>>n1>>s1;
    cin>>c2>>n2>>s2;
    if(c1==c2){
        if(n1==n2){
            if((s1<='C'&&s2<='C')||(s1>'C'&&s2>'C')){
                if(abs(s1-s2)==1) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

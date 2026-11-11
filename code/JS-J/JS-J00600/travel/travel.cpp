#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool f1=0,f2=0,f3=0,f4=0;
    if(c1==c2){
        f1=1;
        int x=(s1[0]-'0')*10+s1[1]-'0';
        int y=(s2[0]-'0')*10+s2[1]-'0';
        if(x==y){
            f2=1;
            char c=s1[2],h=s2[2];
            if((c<='C'&&h<='C')||(c>='D'&&h>='D')){
                f3=1;
                if(!((c=='A'&&h=='C')||(c=='C'&&h=='A'))){
                    f4=1;
                }
            }
        }
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}

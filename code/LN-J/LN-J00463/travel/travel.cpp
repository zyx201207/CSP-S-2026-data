//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool f1=(c1==c2);
    if(!f1){
        cout<<"0000";
        return 0;
    }
    bool f2=(s1[0]==s2[0]&&s1[1]==s2[1]);
    if(!f2){
        cout<<"1000";
        return 0;
    }
    char x1=s1[2],x2=s2[2];
    bool f3=(x1<='C'&&x2<='C'||x1>='D'&&x2>='D');
    if(!f3){
        cout<<"1100";
        return 0;
    }
    bool f4=!(x1=='A'&&x2=='C'||x1=='C'&&x2=='A');
    if(!f4) cout<<"1110";
    else cout<<"1111";
    return 0;
}
//08:59 AC T1
//O(1),how NB I am!

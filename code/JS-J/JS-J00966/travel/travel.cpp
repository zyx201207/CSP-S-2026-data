#include<bits/stdc++.h>
using namespace std;
bool same_side(char a,char b){
    if(a>='A' && a<='C' && b>='A' && b<='C') return true;
    if(a>='D' && a<='F' && b>='D' && b<='F') return true;
    return false;
}
bool near(char a,char b){
    if((a=='A' && b=='C')||(a=='C' && b=='A')) return false;
    return true;
}
int main(){
    //freopen("/home/user/Desktop/travel/travel1.in","r",stdin);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2<<endl;;
    int rs=(s1[0]-'0')*10+(s1[1]-'0');
    int xs=(s2[0]-'0')*10+(s2[1]-'0');
    //cout<<rs<<' '<<xs<<endl;
    int r1=0;int r2=0;int r3=0;int r4=0;
    if(c1==c2){
        r1=1;
        if(rs==xs){
            r2=1;
            if(same_side(s1[2],s2[2])){
                r3=1;
                if(near(s1[2],s2[2])){
                    r4=1;
                }
            }
        }
    }
    cout<<r1<<r2<<r3<<r4<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
//    cout<<s1[0]<<s1[1]<<s1[2];
    if(s1[2]=='F') s1[2]--;
    if(s2[2]=='F') s2[2]--;

    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(!(s1[0]==s2[0] && s1[1]==s2[1])){
        cout<<"000";
        return 0;
    }
    cout<<1;
    int n1=s1[2]-'A'+1,n2=s2[2]-'A'+1;
    if(!( (n1<=3 && n2<=3) || (n1>=4 && n2>=4) ) ){
        cout<<"00";
//        cout<<n1<<n2;
        return 0;
    }
    cout<<1;
    if(abs(n1-n2)!=1){
        cout<<"0";
//        cout<<" "<<n1<<" "<<n2;
        return 0;
    }
    cout<<1;
    return 0;
}

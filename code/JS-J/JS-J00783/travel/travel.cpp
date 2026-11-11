#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000"<<endl;
        return 0;
    }
    int t1=(s1[0]-'0')*10+(s1[1]-'0'),t2=(s2[0]-'0')*10+(s2[1]-'0');
    char p1=s1[2],p2=s2[2];
    int i1=p1-'A'+1,i2=p2-'A'+1;
    if(i1==6)i1--;
    if(i2==6)i2--;
    bool is=false;
    if(t1==t2){
        cout<<1;
        if(p1<='C'&&p2<='C'){
            cout<<1;
            if(abs(i1-i2)==1)cout<<1;
            else cout<<0;
        }
        else if(p1>='D'&&p2>='D'){
            cout<<1;
            if(abs(i1-i2)==1)cout<<1;
            else cout<<0;
        }
        else cout<<"00";
    }
    else cout<<"000";
    return 0;
}

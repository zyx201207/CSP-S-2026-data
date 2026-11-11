#include<bits/stdc++.h>
using namespace std;
int c1=0,c2=0;
string s1,s2;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int a1=((s1[0]-'0')*10+s1[1]-'0'),a2=((s2[0]-'0')*10+s2[1]-'0');
    //cout<<a1<<' '<<a2;
    char c3=s1[2],c4=s2[2];
    if(c1==c2) {
        cout<<1;
        if(a1==a2){
            cout<<1;
            if((c3<='C'&&c4<='C')||(c3>='D'&&c4>='D')){
                cout<<1;
                int sum=(int)abs(c3-c4);
                if(sum==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;


}

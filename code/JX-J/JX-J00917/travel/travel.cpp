#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string x="",y="";
        x+=s1[0],x+=s1[1];
        y+=s2[0],y+=s2[1];
        if(x==y){
            cout<<1;
            if(s1[2]>='D'&&s2[2]>='D'){
                cout<<"11";
            }else if(s1[2]<='C'&&s2[2]<='C'){
                cout<<1;
                if(abs((int)(s1[2]-s2[2]))==1){
                    cout<<1;
                }else cout<<0;
            }else{
                cout<<"00";
            }
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}

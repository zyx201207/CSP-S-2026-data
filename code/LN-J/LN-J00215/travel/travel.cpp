#include<bits/stdc++.h>
using namespace std;
string s;
string ss,sss,ssss;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>ss>>sss>>ssss;
    if(s==sss){
        if(ss[1]==ssss[1]&&ss[0]==ssss[0]){
            if(((ss[2]>='A'&&ss[2]<='C')&&(ssss[2]>='A'&&ssss[2]<='C'))||((ss[2]>='D'&&ss[2]<='F')&&(ssss[2]>='D'&&ssss[2]<='F'))){
                if(abs(int(ss[2])-int(ssss[2]))==1){
                    cout<<1111;
                }
                else{
                    cout<<1110;
                }
            }
            else{
                cout<<1100;
            }
        }
        else{
            cout<<1000;
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

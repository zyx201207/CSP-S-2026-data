#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,v,d,b;
    cin>>s>>v>>d>>b;
    if(s!=d){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if((v[0]==b[0])&&(v[1]==b[1])){
        cout<<1;
        if(((v[2]>='D')&&(b[2]>='D'))||((v[2]<='C')&&(b[2]<='C'))){
            if(v[2]=='D'){
                if(b[2]=='C'){
                    cout<<"00";
                    return 0;
                }
            }
            if(v[2]=='C'){
                if(b[2]=='D'){
                    cout<<"00";
                    return 0;
                }
            }
            cout<<1;
            int ans=abs(v[2]-b[2]);
            if(ans==1)cout<<1;
            else cout<<0;
        }else cout<<"00";
    }else cout<<"000";
    return 0;
}

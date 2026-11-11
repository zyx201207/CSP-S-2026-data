#include<bits/stdc++.h>
using namespace std;
string a="",b="",c="",d="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        string q="",w="";
        for(int i=0;i<=1;i++){
            q=b[i]+q;w=d[i]+w;
        }
        if(q==w){
            cout<<1;
            if(b[2]>='A'&&b[2]<='C'&&b[2]!=d[2]){
                if(d[2]>='A'&&d[2]<='C'){
                    cout<<1;
                    if(((b[2]-1)==d[2])||((d[2]-1)==b[2])){
                        cout<<1;
                    }
                    else{
                        cout<<"0";
                    }
                }
                else{
                    cout<<"00";
                }
            }
            else if((b[2]=='D'||b[2]=='F')&&b[2]!=d[2]){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

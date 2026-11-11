#include <bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int sum;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>ss>>c>>cc;
    if(s==c){
        cout<<"1";
        sum++;
    }else{
        cout<<"0";
    }
    if(sum==1){
        if(ss[1]==cc[1]&&ss[0]==cc[0]){
            cout<<"1";
            sum++;
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }

    if(sum==2){
        if(ss[2]=='C'||ss[2]=='B'||ss[2]=='A'){
            if(cc[2]!='D'&&cc[2]!='F'){
                cout<<"1";
                sum++;
            }else{
                cout<<"0";
            }
        }else{
            if(cc[2]!='C'&&cc[2]!='B'&&cc[2]!='A'){
                cout<<"1";
                sum++;
            }else{
                cout<<"0";
            }
        }
    }else{
        cout<<"0";
    }
    if(sum==3){
        if(ss[2]=='B'||cc[2]=='B'){
            cout<<"1";
        }else if(ss[2]=='D'||cc[2]=='D'){
            cout<<"1";
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }
}

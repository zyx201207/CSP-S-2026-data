#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c,ad,ab,flag=0;
    string b,d;
    cin>>a>>b>>c>>d;
    ab=b[0]*10+b[1];
    ad=d[0]*10+d[1];
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
    }

    if(a==c){
        if(b[1]==d[1]&&b[0]==d[0]){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }


    if(a==c){
        if(ab==ad){
            if((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D')){
                cout<<1;
            }else if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
                cout<<1;
            }else{
                flag+=1;
                cout<<0;
            }
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }

    if(a==c){
        if(b[2]==d[2]){
            if(ad==ab||ad==ab+1||ad==ab-1){
                cout<<1;
            }
        }else if(b[2]==d[2]+1||b[2]==d[2]-1){
            if(!flag){
                if(ab==ad){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
            cout<<0;
            }
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}

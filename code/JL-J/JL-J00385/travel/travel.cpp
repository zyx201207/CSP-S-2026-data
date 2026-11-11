#include<bits/stdc++.h>-
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,d;
    char m[5],n[5];
    cin>>a;
    for(int i=1;i<=3;i++){
        cin>>m[i];
    }
    cin>>d;
    for(int i=1;i<=3;i++){
        cin>>n[i];
    }
    char h;
    char p;
    h=n[1];
    h+=n[2]*10;
    p=n[3];
    char k;
    char q;
    k=m[1];
    k+=m[2]*10;
    q=m[3];
    int b=int(k);
    int e=int(h);
    char f=p;
    char c=q;
    if(a==d){
        cout<<"1";
        if(b==e){
            cout<<"1";
            if('c'=='C'&&'f'=='D'||'c'=='D'&&'f'=='C'){
                cout<<"0";
            }
            if('c'>='D'&&'f'>='D'&&'c'!='f'){
                cout<<"1";
            }
            else if('c'<='C'&&'f'<='C'&&'c'!='f'){
                cout<<"1";
            }

            else{
                cout<<"0";
            }
        }
        else{
            cout<<"00";
        }
    }
    else{
        cout<<"000";
    }
    if(b!=e||'c'=='f'||'c'=='C'&&'f'=='D'||'c'=='D'&&'f'=='C'){
        cout<<"0";
    }
    else if(b==e&&'c'!='f'){
        if('c'=='D'&&'f'=='F'||'c'=='F'&&'f'=='D'){
            cout<<"1";
            return 0;
        }
        else if('c'>='A'&&'c'<='C'&&'f'>='A'&&'f'<='C'){
            if('c'=='B'||'f'=='B'){
                cout<<"1";
                return 0;
            }
        }
        cout<<"0";
    }
    return 0;
}

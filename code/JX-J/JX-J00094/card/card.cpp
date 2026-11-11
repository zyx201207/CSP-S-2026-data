#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c){
    cout<<1;
}else{
    cout<<0<<0<<0<<0;
    return 0;
}
if(b[1]==d[1]&&b[0]==b[0]){
    cout<<1;
}else{
    cout<<0<<0<<0;
    return 0;
}
if(b[2]=='A'&&d[2]=='B'){
    cout<<1;
}else{
    if(b[2]=='B'&&d[2]=='c')
        cout<<1;
    else{
        if(b[2]=='D'&&d[2]=='F')
            cout<<1;
        else{
            if(b[2]=='A'&&d[2]=='C')
                cout<<1;
            else{
    if(d[2]=='A'&&b[2]=='B'){
    cout<<1;
}else{
    if(d[2]=='B'&&b[2]=='c')
        cout<<1;
    else{
        if(d[2]=='D'&&b[2]=='F')
            cout<<1;
        else{
            if(d[2]=='A'&&b[2]=='C')
                cout<<1;
                else{
                    cout<<0<<0;
                    return 0;
                }
        }
    }
}
}
        }
    }

}
if(b[2]=='A'&&d[2]=='B'){
    cout<<1;
}else{
    if(b[2]=='B'&&d[2]=='c')
        cout<<1;
    else{
        if(b[2]=='D'&&d[2]=='F')
            cout<<1;
            else{
    if(d[2]=='A'&&b[2]=='B'){
    cout<<1;
}else{
    if(d[2]=='B'&&b[2]=='c')
        cout<<1;
    else{
        if(d[2]=='D'&&b[2]=='F')
            cout<<1;
                else{
                    cout<<0;
                    return 0;
                }
        }
    }
}
}
        }


return 0;
}

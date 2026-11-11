#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in""r""stdin")
    freopen("travel.out""w""stdout")
    string a,b,c,d;
    for(int i=1;i<=2;i++){
        cin>>a[i];
    }
    for(int i=1;i<=3;i++){
        cin>>b[i];
    }
    for(int i=1;i<=2;i++){
        cin>>c[i];
    }
    for(int i=1;i<=3;i++){
        cin>>d[i];
    }
    if(a[2]==c[2]&&a[2]!=0&&c[2]!=0){
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]&&b[2]==d[2]){
            cout<<1;
            if(b[3]=='F'&&d[3]=='D'||b[3]=='D'&&d[3]=='F'||b[3]=='A'&&d[3]=='B'||b[3]=='A'&&d[3]=='C'||b[3]=='B'&&d[3]=='A'||b[3]=='B'&&d[3]=='C'||b[3]=='C'&&d[3]=='A'||b[3]=='C'&&d[3]=='B'){
                cout<<1;
                if(b[3]=='F'&&d[3]=='D'||b[3]=='D'&&d[3]=='F'||b[3]=='A'&&d[3]=='B'||b[3]=='B'&&d[3]=='A'||b[3]=='B'&&d[3]=='C'||b[3]=='C'&&d[3]=='B'){
                    cout<<1;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<0<<0;
                return 0;
            }
        }
        else{
            cout<<0<<0<<0;
            return 0;
        }
    }
    else if(a[2]!=c[2]&&a[2]!=0&&c[2]!=0){
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}


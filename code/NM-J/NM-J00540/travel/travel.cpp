#include<bits/stdc++.h>
using namespace std;
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]){
        if(a[1]==c[1]){
            cout<<1<<" ";
            if(b[0]==d[0]&&b[1]==d[1]){
                cout<<1<<" ";
                if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
                    if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
                        cout<<1<<" ";
                        if(b[3]=='A'&&d[3]=='B') cout<<1;
                        if(b[3]=='B'&&d[3]=='C') cout<<1;
                        if(b[3]=='A'&&d[3]=='C') cout<<0;
                    }
                }
                if(b[3]=='D'||b[3]=='E'){
                    if(d[3]=='D'||d[3]=='E'){
                        cout<<1<<" "<<1;

                    }
                }
                if(b[3]=='A'||b[3]=='B'||b[3]=='C'){
                    if(d[3]=='D'||d[3]=='E'){
                        cout<<0<<" "<<0;
                    }
                }
                if(d[3]=='A'||d[3]=='B'||d[3]=='C'){
                    if(b[3]=='D'||b[3]=='E'){
                        cout<<0<<" "<<0;
                    }
                }
            }
            else cout<<0<<" "<<0<<" "<<0;
        }
    }
    if(a[1]!=c[1]||a[0]!=c[0]){
        cout<<0<<" "<<0<<" "<<0<<" "<<0;
    }
    return 0;
}

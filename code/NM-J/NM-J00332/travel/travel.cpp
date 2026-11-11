#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b;
    cin>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<"1";
            if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
                cout<<"1";
                if(b[2]=='A' and d[2]=='B'||b[2]=='B' and d[2]=='A'||b[2]=='B' and d[2]=='C'||b[2]=='C' and d[2]=='B'||b[2]=='D' and d[2]=='F'||b[2]=='F' and d[2]=='D'){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"0";
            }
        }
        else{
            cout<<"0";
        }
    }
    else{
        cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

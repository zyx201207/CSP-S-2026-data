#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c>>b>>d;
    if(a==b){
        if(a[0]!='0'&&a[1]!='1'&&b[0]!='0'&&b[1]!='1'){
        cout<<"1";
        if(c[1]==d[1]&&c[0]==d[0]){
            cout<<"1";
            if((c[2]<='C'&&d[2]<='C')||(c[2]=='D'&&d[2]=='F')||(c[2]=='F'&&d[2]=='D')){
                cout<<"1";
                if(c[2]==d[2]+1||d[2]==c[2]+1){
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
        }

    }
    else{
        cout<<"0000";
    }

    return 0;
}

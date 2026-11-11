#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0] and b[1]==d[1]){
            cout<<"1";
            if((b[2]-'A'<=2 and d[2]-'A'>2) or (b[2]-'A'>2 and d[2]-'A'<=2)){
                cout<<"00";
            }
            else{
                cout<<"1";
                int x=b[2]-'A',y=d[2]-'A';
                if((x==0 and y==2) or (x==2 and y==0)){
                    cout<<"0";
                }
                else{
                    cout<<"1";
                }
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

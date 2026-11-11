#include<bits/stdc++.h>
using namespace std;
 string a,b;
 string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<'1';
        int x,y;
        x=(b[0]-'0')*10+b[1]-'0';
        y=(d[0]-'0')*10+d[1]-'0';
        if(x==y){
            cout<<'1';
            x=b[2]-65;
            y=d[2]-65;
            if((x<=2&&y<=2)  ||  (x>2&&y>2)){
                cout<<1;
                if(abs(x-y)==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }

    return 0;
}

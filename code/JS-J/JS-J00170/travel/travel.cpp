#include<bits/stdc++.h>
using namespace std;
string a,x,b,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if((a[0]-'0')*10+a[1]-'0'==(b[0]-'0')*10+b[1]-'0'){
        cout<<1;
        if((x[0]-'0')*10+x[1]-'0'==(y[0]-'0')*10+y[1]-'0'){
            cout<<1;
            if((x[2]-'A'>=0&&y[2]-'A'<=2&&x[2]-'A'<=2&&y[2]-'A'>=0)||(x[2]-'A'>=3&&y[2]-'A'<=5&&x[2]-'A'<=5&&y[2]-'A'>=3)){
                cout<<1;
                if((x[2]+1==y[2]&&x[2]!='C')||(y[2]+1==x[2]&&y[2]!='C')){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int x,y;
string a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>a>>y>>b;
    if(x==y){
        cout<<1;
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<1;
            if(('A'<=a[2]&&a[2]<='C'&&'A'<=b[2]&&b[2]<='C')||('D'<=a[2]&&a[2]<='F'&&'D'<=b[2]&&b[2]<='F')){
                cout<<1;
                if(abs(a[2]-b[2])==1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
                return 0;
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
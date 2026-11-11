#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[0]==d[0] and b[1]==d[1]){
            cout<<1;
            if(b[2]<=67 and d[2]<=67 or b[2]>67 and d[2]>67){
                cout<<1;
                if(abs(int(b[2])-int(d[2]))==1){
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

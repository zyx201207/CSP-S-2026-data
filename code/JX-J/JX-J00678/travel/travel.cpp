#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            if(c[2]==d[2])
                cout<<1;
            else
                cout<<0;
        }
        else
            cout<<0;

    }
    else
        cout<<0;
}

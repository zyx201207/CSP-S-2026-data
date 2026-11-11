#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char m,n;
    cin>>a>>b>>m>>c>>d>>n;
    if(a==c){
         cout<<'1';
         if(b==d){
            cout<<'1';
            if(m>='A'&&m<='C'&&n>='A'&&n<='C'||m>='D'&&m<='F'&&n>='D'&&n<='F'){
                cout<<'1';
                if(m==n+1||m==n-1) cout<<'1';
                else cout<<'0';
            }
            else cout<<"00";
         }
         else cout<<"000";
    }else cout<<"0000";
    return 0;
}

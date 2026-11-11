#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int flag1=0;
    if (a[0]==c[0] && a[1]==c[1]){
        cout<<1;
        flag1=1;
    }
    else{
        cout<<0;
    }
    int flag2=0;
    if (b[0]==d[0] && b[1]==d[1] && flag1==1){
        cout<<1;
        flag2=1;
    }
    else{
        cout<<0;
    }
    int flag3=0;
    if (flag1==1 && flag2==1){
        if ((b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D')){
            cout<<1;
            flag3=1;
        }
        else if (b[2]=='A' || b[2]=='B' || b[2]=='C'){
            if (d[2]=='A' || d[2]=='B' || d[2]=='C'){
                flag3=1;
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    if (flag1==1 && flag2==1 && flag3==1){
        if (b[2]=='A' && d[2]=='B'){
            cout<<1;
        }
        else if (b[2]=='B'){
            if (d[2]=='A'){
                cout<<1;
            }
            else if (d[2]=='C'){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else if (b[2]=='C' && d[2]=='B'){
            cout<<1;
        }
        else if (b[2]=='D' && d[2]=='F'){
            cout<<1;
        }
        else if (b[2]=='F' && d[2]=='D'){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
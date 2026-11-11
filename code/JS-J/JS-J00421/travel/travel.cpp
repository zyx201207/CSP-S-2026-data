#include<bits/stdc++.h>
using namespace std;
int a,b;
string rs,xs;
bool chk1(char x,char y){
    return !((x >= 'A' && x <= 'C') ^ (y >= 'A' && y <= 'C'));
}
bool chk2(char x,char y){
    return (((x == 'D' && y == 'F') || (x == 'F' && y == 'D') || abs(x - y) == 1) && chk1(x,y));
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);

    cin>>a>>rs;
    cin>>b>>xs;

    if(a == b){
        if(rs[0] == xs[0] && rs[1] == xs[1]){
            if(chk1(rs[2],xs[2])){
                if(chk2(rs[2],xs[2])) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

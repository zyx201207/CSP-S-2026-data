#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>a>>c>>b>>d;
    if(a==b) cout <<1;
    else{
        cout <<"0000";
        return 0;
    }
    int m=(c[0]-'0')*10+(c[1]-'0');
    int n=(d[0]-'0')*10+(d[1]-'0');
    if(m==n) cout <<1;
    else{
        cout <<"000";
        return 0;
    }
    int x=c[2]-'A',y=d[2]-'A';
    if((x>=0 && x<=2 && y>=0 && y<=2) || (x>=3 && x<=5 && y>=3 &&y<=5)) cout <<1;
    else{
        cout <<"00";
        return 0;
    }
    if((x>=0 && x<=2 && y>=0 && y<=2 && abs(x-y)==1) || (x>=3 && x<=5 && y>=3 && y<=5)) cout <<1;
    else cout <<0;
    return 0;
}

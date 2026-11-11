#include<bits/stdc++.h>
using namespace std;
string x,y,n,m;
long long a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>n>>y>>m;
    for(int i = 0;i < x.size();i++){
        a *= 10;
        a += x[i] - '0';
    }
    for(int i = 0;i < y.size();i++){
        b *= 10;
        b += y[i] - '0';
    }
    if(a == b && a != 1 && b != 1 && a != 16 && b != 16){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }//1
    for(int i = 0;i <= 1;i++){
        c *= 10;
        c += n[i] - '0';
    }
    for(int i = 0;i <= 1;i++){
        d *= 10;
        d += m[i] - '0';
    }
    if(c == d){
        cout<<1;
    }
    else{
        cout<<0<<0<<0;
        return 0;
    }//2
    if(n[2] == m[2]){
        cout<<0<<0;
        return 0;
    }
    if(n[2] >= 'A' && n[2] <= 'C' && m[2] >= 'A' && m[2] <= 'C'){
        cout<<1;
    }
    else if(n[2] >= 'D' && n[2] <= 'F' && m[2] >= 'D' && m[2] <= 'F' && n[2] != 'E' && m[2] != 'E'){
        cout<<1;
    }
    else{
        cout<<0<<0;
        return 0;
    }
    if(n[2] + 1 == m[2] || n[2] - 1 == m[2]){
        if((n[2] == 'C' && m[2] == 'D') || (n[2] == 'D' && m[2] == 'C')){
            cout<<0;
            return 0;
        }
        else{
            cout<<1;
            return 0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}

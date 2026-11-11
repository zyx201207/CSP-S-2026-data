#include<bits/stdc++.h>
using namespace std;
char a[5];
char b[5];
char c[5];
char d[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char z[4] = {};
    for(int i = 1;i <= 2;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= 3;i++){
        cin >> b[i];
    }
    for(int i = 1;i <= 2;i++){
        cin >> c[i];
    }
    for(int i = 1;i <= 3;i++){
        cin >> d[i];
    }
    if(a[0] == c[0] && a[1] == c[1]){
        a[0] = '1';
    }
    else{
        cout << "0000";
        return 0;
    }
    if(b[1] == d[1] && b[0] == d[0]){
        z[1] = '1';
        if(b[2] == d[2]){
            z[2] = '1';
        }
        if((b[2] == 'D' && d[2] == 'D') || (b[2] =='F' && d[2] == 'D')){
            z[2] = '1';
        }
        if((b[2] =='A' && d[2] == 'B') || (b[2] =='A' && d[2] == 'C') || (b[2] =='B' && d[2] == 'A') || (b[2] =='B' && d[2] == 'C') || (b[2] =='C' && d[2] == 'A') || (b[2] =='C' && d[2] == 'B')){
            z[2] = '1';
        } 
    }
    if(b[0] == d[0] && b[1] == d[1]){
        if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'C') ||(b[2] == 'B' && d[2] == 'A') ||(b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B') || (b[2] == 'D' && d[2] == 'F') ||(b[2] == 'F' && d[2] == 'D')){
            z[3] = '1';
        }
    }
    for(int i = 1;i <= 3;i++){
        cout << z[i];
    }
    return 0;   
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","l",stdin);
    freopen("travel.out","r",stdout);
    string a,b,c,d;
    int h=0,k=0,l=0;
    cin >> a >> b >> c >> d;
    if(a == c){
        h = h+1;
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(h ==1 && b[1] == d[1]){
        k = k+1;
        cout << "1";
    }
    else{
        cout << "0";
    }
    if((h==1 && k ==1 &&(b[2] == 'D' || b[2]=='F') && (d[2] == 'D' || d[2] =='F'))) {
        l = l+1;
        cout << "1";
    }
    else if(h==1 && k ==1 && (b[2] == 'A' || b[2]=='B' || b[2]=='C') && (d[2] == 'A' || d[2]=='B' || d[2]=='C')){
        l = l+1;
        cout << "1";
    }
    else{
        cout << "0";
    }
    if(h==1 && k==1 && l==1 ){
        if(b[2] == 'B' || d[2] == 'B'){
            cout << "1";
        }
        else if(b[2] == 'D' || d[2] == 'D'){
            cout << "1";
        }
    }
    else{
        cout << "0";
    }
    return 0;
}

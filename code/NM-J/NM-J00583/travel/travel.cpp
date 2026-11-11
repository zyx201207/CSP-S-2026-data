#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
char e, f;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin  >>  a  >>  b  >>  e  >>  c  >>  d  >>  f;
    if(a == c){
        cout  <<  1;
    }else{
        cout  <<  "0000";
        return 0;
    }
    if(b == d){
        cout  <<  1;
    }else{
        cout  <<  "000";
        return 0;
    }
    if(e < 'D' && f < 'D'){
        cout  <<  1;
    }else if(e >'C' && f > 'C'){
        cout  <<  1;
    }else{
        cout  <<  "00";
        return 0;
    }
    if(e - 1 == f || e + 1 == f){
        cout  <<  1;
    }else{
        cout  <<  "0";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int r1, r2, r3, r4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){
        r1 = 1;
    }else{
        r1 = 0;
    }
    if(r1 == 0){
        r2 = 0;
    }else{
        string k1 = s2.substr(0,2), k2 = s4.substr(0,2);
        if(k1 == k2){
            r2 = 1;
        }else{
            r2 = 0;
        }
    }
    if(r2 == 0){
        r3 = 0;
    }else{
        char c1 = s2[2], c2 = s4[2];
        if(c1 == 'A' && c2 == 'B'){
            r3 = 1;
        }else if(c1 == 'B' && c2 == 'C'){
            r3 = 1;
        }else if(c1 == 'D' && c2 == 'F'){
            r3 = 1;
        }else if(c1 == 'B' && c2 == 'A'){
            r3 = 1;
        }else if(c1 == 'C' && c2 == 'B'){
            r3 = 1;
        }else if(c1 == 'F' && c2 == 'D'){
            r3 = 1;
        }else if(c1 == 'A' && c2 == 'C'){
            r3 = 1;
        }else if(c1 == 'C' && c2 == 'A'){
            r3 = 1;
        }else{
            r3 = 0;
        }
    }
    if(r3 == 0){
        r4 = 0;
    }else{
        char c1 = s2[2], c2 = s4[2];
        if(c1 == 'A' && c2 == 'B'){
            r4 = 1;
        }else if(c1 == 'B' && c2 == 'C'){
            r4 = 1;
        }else if(c1 == 'D' && c2 == 'F'){
            r4 = 1;
        }else if(c1 == 'B' && c2 == 'A'){
            r4 = 1;
        }else if(c1 == 'C' && c2 == 'B'){
            r4 = 1;
        }else if(c1 == 'F' && c2 == 'D'){
            r4 = 1;
        }else{
            r4 = 0;
        }
    }
    cout << r1 << r2 << r3 << r4;
    return 0;
}

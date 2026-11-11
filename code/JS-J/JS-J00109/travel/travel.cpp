#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b;
bool flag,yes,fg;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char n[10] = {'A','B','C','D','F'};
    cin >> s1 >> s2 >> s3 >> s4;
    if(s1 == s3){
        cout << 1;
        fg = 1;
    }
    else{
        cout << 0;
    }
    for(int i = 0;i<= 1;i++){
        a = a * 10 + (s2[i] - '0');
        b = b * 10 + (s4[i] - '0');
    }
    if(a == b && fg){
        cout << 1;
        yes = 1;
    }
    else{
        cout << 0;
    }
    if(s2[2]  <= 'C' && s4[2] <= 'C' && yes){
        cout << 1;
    }
    else if(s2[2] >= 'D' && s4[2] >= 'D' && yes){
        cout << 1;
    }
    else{
        cout << 0;
    }
    char c = s2[2];
    char d = s4[2];
    for(int i = 0;i <= 3;i++){
        if(c == n[i] && d == n[i + 1] && yes){
            flag = 1;
        }
        if(c == n[i + 1] && d == n[i] && yes){
            flag = 1;
        }
    }
    if(s2[2] == 'C' && s4[2] == 'D'){
        flag = 0;
    }
    if(s2[2] == 'D' && s4[2] == 'C'){
        flag = 0;
    }
    if(flag){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}

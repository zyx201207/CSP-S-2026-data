#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int ra=(s1[0]-'0')*10+s1[1]-'0', xa=(s3[0]-'0')*10+s3[1]-'0', rb=(s2[0]-'0')*10+s2[1]-'0', xb=(s4[0]-'0')*10+s4[1]-'0';
    char rc=s2[2], xc=s4[2];
    bool a, b, c, d;
    if(ra==xa){
        a=true;
        if(rb==xb){
            b=true;
            if(rc<='C' && xc<='C'){
                c=true;
                if(rc+1==xc || rc-1==xc){
                    d=true;
                }else{
                    d=false;
                }
            }else if(rc>='D' && xc>='D'){
                c=true;
                d=true;
            }else{
                c=false;
                d=false;
            }
        }else{
            b=false;
            c=false;
            d=false;
        }
    }else{
        a=false;
        b=false;
        c=false;
        d=false;
    }
    cout << a << " " << b << " " << c << " " << d;
    return 0;
}

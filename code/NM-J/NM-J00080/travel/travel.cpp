#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c;
    string s;
    int cc;
    string ss;
    cin >> c;
    cin >> s;
    cin >>cc;
    cin >>ss;
    int is=0;
    if(c==cc){
        cout <<1;
        }else{
        cout <<0 << 0 << 0 << 0;
        is++;
    }

    int a=s[0]-'0';
    int b=s[1]-'0';
    int e=ss[0]-'0';
    int f=ss[1]-'0';
    int m=a*10+b;
    int n=e*10+f;
    if(m==n&&is==0){
        cout << 1;
    } else{
        if(is==0) {
            cout << 0 <<0 << 0;
            }
        is++;
    }
    if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&is==0){
       if((ss[2]=='A'||ss[2]=='B'||ss[2]=='C')&&is==0){
            cout << 1;
        }else{
            if(is==0) cout << 0 <<0;
            is++;
        }
    }else{
        if((ss[2]=='D'||ss[2]=='F')&&is==0){
            cout << 1;
        }else{
            if(is==0) cout << 0 <<0;
            is++;
            }
        }
    if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')&&is==0) {
        cout << 1;
        }else{
            if((s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')&&is==0){
                cout << 1;
                }else{
                    if((s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')&&is==0) {
                        cout << 1;
                        }else{
                            if(is==0) cout << 0;
                            }
                        }
                    }
    return 0;
}

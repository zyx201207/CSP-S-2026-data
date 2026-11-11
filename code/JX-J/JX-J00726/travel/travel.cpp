#include <bits/stdc++.h>
using namespace std;
string c[10],s[10];
bool a,b,e;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c[1]>>s[1]>>c[2]>>s[2];
    if(c[1]==c[2]){
        cout << 1;
        if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
            cout << 1;
            if(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C'){
                    a =1;

            }
            else{
                a = 0;
            }
            if(s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C'){
                b =1;
            }
            else{
                b = 0;
            }
            if(a==b){
                cout << 1;
                if(a==1&&b==1){
                    if(abs(s[1][2]-s[2][2])==1) cout << 1;
                    else cout << 0;


                }
                if(a==0&&b==0){
                    if(abs(s[1][2]-s[2][2])==2)cout << 1;
                    else cout << 0;


                }


            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout << 0<<0<<0;
        }
    }
    else{
        cout << 0 <<0<<0<<0;
    }




return 0;


}

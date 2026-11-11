#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    string a1,a2,a3,a4;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        a1="1";
        for(int i=0;i<=1;i++){
            if(s1[i]==s2[i])
                a2="1";
            else{
                a2="0";
                a3="0";
                a4="0";
                cout << a1 << a2 << a3 << a4;
            }
        }
        if(a4!="0"){
            if(s1[2]==67&&s2[2]==68){
                a3="0";
                a4="0";
                cout << a1 << a2 << a3 << a4;
            }

            else if(s1[2]==68&&s2[2]==67){
                a3="0";
                a4="0";
                cout << a1 << a2 << a3 << a4;
            }

            else a3="1";

            if(a4!="0"){
            if (s1[2]=='A'&&s2[2]=='B'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else if(s1[2]=='B'&&s2[2]=='C'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else if(s1[2]=='D'&&s2[2]=='F'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else if(s1[2]=='B'&&s2[2]=='A'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else if(s1[2]=='C'&&s2[2]=='B'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else if(s1[2]=='F'&&s2[2]=='D'){
                a4="1";
                cout << a1 << a2 << a3 << a4;
                }
            else {
                a4="0";
                cout << a1 << a2 << a3 << a4;
                }
            }
        }
    }

    else cout << "0000";
    return 0;
}

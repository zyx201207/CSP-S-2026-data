#include <bits/stdc++.h>
using namespace std;
string a,b,sa,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sa;
    cin>>b>>sb;
    if(a==b){
        cout<<"1";
        if(sa[0]==sb[0]&&sa[1]==sb[1]){
            cout<<"1";
            if((sa[2]>='A'&&sa[2]<='C'&&sb[2]>='A'&&sb[2]<='C')||(sa[2]>='D'&&sa[2]<='F'&&sb[2]>='D'&&sb[2]<='F')){
                cout<<"1";
                if((sa[2]=='A'&&sb[2]=='B')||(sa[2]=='B'&&sb[2]=='A')||(sa[2]=='B'&&sb[2]=='C')||(sa[2]=='C'&&sb[2]=='B')||(sa[2]=='D'&&sb[2]=='F')||(sa[2]=='F'&&sb[2]=='D')){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

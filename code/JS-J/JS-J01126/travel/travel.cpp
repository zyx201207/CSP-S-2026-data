#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    char x=b1[2],y=b2[2];
    if(a1==a2){
        cout<<'1';
        if(b1[0]==b2[0] && b1[1]==b2[1]){
            cout<<'1';
            if((b1[2]=='A' && (b2[2]=='B' || b2[2]=='C')) ||
               (b1[2]=='B' && (b2[2]=='A' || b2[2]=='C')) ||
               (b1[2]=='C' && (b2[2]=='A' || b2[2]=='B')) ||
               (b1[2]=='D' && b2[2]=='F') ||
                (b1[2]=='F' && b2[2]=='D') ){
                cout<<'1';
                if((x+1)==y || (y+1)==x){
                    cout<<'1';
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

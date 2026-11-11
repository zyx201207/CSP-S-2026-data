#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=18;i++){
    if(c1==c2){
        cout<<1;
        }else{
        cout<<0;
    }
    if(s1[1]==s2[1]&&s1[2]==s2[2]){
        cout<<1;
        }else{
            cout<<0;
        }
    if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='E'||s1[3]=='E'&&s2[3]=='F'||s1[3]=='F'&&s2[3]=='E'||s1[3]=='E'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='A'){
        cout<<1;
        }else{
                cout<<0;
            }
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
                    cout<<1;
                }else{
                    cout<<0;
                }

    }

    return 0;

}

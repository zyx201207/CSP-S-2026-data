#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int side1,side2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') side1=0;
            else side1=1;
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') side2=0;
            else side2=1;
            if(side1==side2){
                cout<<"1";
                if(s1[2]=='A'&&s2[2]=='B') cout<<"1\n";
                else if(s1[2]=='B'&&s2[2]=='A') cout<<"1\n";
                else if(s1[2]=='B'&&s2[2]=='C') cout<<"1\n";
                else if(s1[2]=='C'&&s2[2]=='B') cout<<"1\n";
                else if(s1[2]=='D'&&s2[2]=='F') cout<<"1\n";
                else if(s1[2]=='F'&&s2[2]=='D') cout<<"1\n";
                else cout<<"0\n";
            }
            else{
                cout<<"00\n";
            }
        }
        else{
            cout<<"000\n";
        }
    }
    else{
        cout<<"0000\n";
    }
    return 0;
}

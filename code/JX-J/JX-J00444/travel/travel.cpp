#include <bits/stdc++.h>
using namespace std;

string s1,s2,c1,c2;
char f[10]={'0','A','B','C','D','F','\0'};

bool tyc(){
    if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
        if(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'){
            return 1;
        }
        else return 0;
    }else{
        if(s2[2]=='D' or s2[2]=='F'){
            return 1;
        }else return 0;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s2[0]==s1[0] and s2[1]==s1[1]){
            cout<<"1";
            if(tyc()){
                cout<<"1";
                int p=s1[2]-'A'+1;
                if(s2[2]==f[p-1] or s2[2]==f[p+1]){
                    cout<<"1";
                }
                else{
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
    return 0;
}

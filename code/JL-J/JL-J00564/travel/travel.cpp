#include <bits/stdc++.h>
using namespace std;

int a1,a2;
string s1,s2,s11,s21;
char s12,s22;
char chL[3]={'A','B','C'},chR[2]={'D','F'};

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>s1>>a2>>s2;
    if(a1==a2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    s11=s1[0]+s1[1];s12=s1[2];
    s21=s2[0]+s2[1];s22=s2[2];
    if(s11==s21) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if(s12=='A'||s12=='B'||s12=='C'){
        if(s22=='A'||s22=='B'||s22=='C'){
            cout<<1;
            if(chL[s12-'A'+1]==s22||(s12-'A'!=0&&chL[s12-'A'-1]==s22)) cout<<1;
            else{
                cout<<0;
                return 0;
            }
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(s12=='D'||s12=='F'){
        if(s22=='D'||s22=='F'){
            cout<<"11";
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    return 0;
}

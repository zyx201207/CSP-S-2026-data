#include<bits/stdc++.h>
using namespace std;
bool check(string s1,string s2){
    bool lc=((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'));
    return lc;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1==c2){
        cout<<1;
        string r1=s1.substr(0,2);
        string r2=s2.substr(0,2);
        if (r1==r2){
            cout<<1;
            if (check(s1,s2)){
                cout<<1;
                if ((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))
                    cout<<1;
                else
                    cout<<0;
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}

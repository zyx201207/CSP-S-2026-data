#include<bits/stdc++.h>

using namespace std;
string c1,s1,c2,s2;
unordered_map<char,int>m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    m['A']=1,m['B']=2,m['C']=3,m['D']=4,m['E']=5;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))){
                if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                    if(abs(m[s1[2]]-m[s2[2]])==1)cout<<"1111";
                    else {
                            cout<<"1110";
                    }
                }
                if(s1[2]=='D'||s1[2]=='E'){
                    if(abs(m[s1[2]]-m[s2[2]])==1)cout<<"1111";
                    else {
                            cout<<"1110";
                    }
                }
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}

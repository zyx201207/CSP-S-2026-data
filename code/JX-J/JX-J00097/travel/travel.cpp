#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string s;
int t=4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        s+='1';
        if(s1[0]==s2[0] && s2[1]==s1[1]){
            s+='1';
            if((s1[2]>='D' && s2[2]>='D') || (s1[2]<='C' && s2[2]<='C')){
                s+='1';
                if(s1[2]=='A'){
                    if(s2[2]=='B'){
                        s+='1';
                    }
                }
                else if(s1[2]=='B'){
                    if(s2[2]<='C'){
                        s+='1';
                    }
                }
                else if(s1[2]=='C'){
                    if(s2[2]=='B'){
                        s+='1';
                    }
                }
                else{
                    s+='1';
                }
            }
        }
    }
    int l=s.size();
    for(int i=0;i<l;i++){
        t--;
        cout<<s[i];
    }
    while(t--){
        cout<<'0';
    }
    return 0;
}

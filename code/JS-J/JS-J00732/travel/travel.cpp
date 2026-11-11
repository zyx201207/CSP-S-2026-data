#include <bits/stdc++.h>
using namespace std;

int m[6]={0,0,0,1,-1,1};

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            if(s1[2]>s2[2]){
               swap(s1,s2);
            }
            if(m[s1[2]-'A']==m[s2[2]-'A']){
                if(s1[2]=='A'&&s2[2]=='C'){
                    cout<<"1110\n";
                }else{
                    cout<<"1111\n";
                }
            }else{
                cout<<"1100\n";
            }
        }else{
            cout<<"1000\n";
        }
    }else{
        cout<<"0000\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int s[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a2,b,b2;
    cin>>a>>a2>>b>>b2;
    if(a==b){
        s[1]=1;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            s[2]=1;
            if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')){
                s[3]=1;
                if(abs((a2[2]-'A')-(b2[2]-'A'))==1) s[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++) cout<<s[i];
    return 0;
}

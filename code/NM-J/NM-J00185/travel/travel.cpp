#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
char num[4];
int a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    num[0]='0';
    num[1]='0';
    num[2]='0';
    num[3]='0';
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        num[0]='1';

        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            num[1]='1';

            if(s1[2]-'A'<=2&&s2[2]-'A'<=2){
                num[2]='1';

                if(s1[2]-'A'-s2[2]+'A'==1||s1[2]-'A'-s2[2]+'A'==-1){
                    num[3]='1';
                }
            }else if(s1[2]-'A'>2&&s2[2]-'A'>2){
                num[2]='1';
                num[3]='1';
            }
        }
    }

    for(int i=0;i<4;i++){
        cout<<num[i];
    }
    return 0;
}

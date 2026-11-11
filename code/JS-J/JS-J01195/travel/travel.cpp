#include<bits/stdc++.h>
using namespace std;
string a1,a2;
string b1,b2;
bool flag[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        flag[0]=true;
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            flag[1]=true;
            if(a2[2]<='C'&&b2[2]<='C'||a2[2]>'C'&&b2[2]>'C'){
                flag[2]=true;
                if(abs(a2[2]-b2[2])==1){
                    flag[3]=true;
                }
            }
        }
    }
    for(int i=0;i<4;++i)
        cout<<flag[i];
    return 0;
}

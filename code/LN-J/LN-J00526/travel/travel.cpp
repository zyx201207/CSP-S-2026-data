#include <bits/stdc++.h>
using namespace std;
int a[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[1]=1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            a[2]=1;
            if((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C')){
                a[3]=1;
                if(abs(s1[2]-s2[2])<=1){
                    a[4]=1;
                }
            }
        }
    }
    for(int i=1;i<5;i++){
        cout<<a[i];
    }
    return 0;
}

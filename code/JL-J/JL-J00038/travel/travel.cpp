#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    int s[30]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1==b1){
        s[1]=1;
        if(a2[1]==b2[1]&&a2[0]==b2[0]){
            s[2]=1;
            if((a2[2]!='F'&&a2[2]!='D'&&b2[2]!='F'&&b2[2]!='D')||(a2[2]=='F'&&a2[2]=='D'&&b2[2]=='F'&&b2[2]=='D')){
                s[3]=1;
                if((a2[2]=='F'&&b2[2]=='D')||(a2[2]=='B'&&b2[2]=='C')||(a2[2]=='A'&&b2[2]=='B')){
                    s[4]=1;
                }
            }
        }
    }
    cout << s[1] << s[2] << s[3] << s[4];
    return 0;
}

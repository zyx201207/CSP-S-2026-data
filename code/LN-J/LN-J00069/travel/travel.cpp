#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int sumj,sumi;
    string c[10];
    for(int i=0;i<4;i++)
        cin>>c[i];
    if(c[0]!=c[2])
        cout<<"0000";
    else{
        if(c[1][0]!=c[3][0]||c[1][1]!=c[3][1])
            cout<<"1000";
        else{
            if(c[1][2]=='A'||c[1][2]=='B'||c[1][2]=='C')
                sumj=0;
            else
                sumj=1;
            if(c[3][2]=='A'||c[3][2]=='B'||c[3][2]=='C')
                sumi=0;
            else
                sumi=1;
            if(sumi!=sumj)
                cout<<"1100";
            else{
                if(sumj==1){
                    cout<<"1111";
                    return 0;}
                if(c[1][2]-c[3][2]==1||c[3][2]-c[1][2]==1)
                    cout<<"1111";
                else
                    cout<<"1110";
                }
        }
    }
    return 0;
}

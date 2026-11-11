#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        for(int i=0;i<=1;i++){
            if(s1[i]!=s2[i]){
                cout<<"000";
                goto Exit;
            }
        }
        cout<<1;

        bool same3=0,same4=0;
        if(s1[2]=='D' and s2[2]=='F') same3=1,same4=1;
        if(s1[2]=='F' and s2[2]=='D') same3=1,same4=1;
        if(s1[2]!='D' and s1[2]!='F' and s2[2]!='D' and s2[2]!='F') same3=1;
        if(same3==0){
            cout<<"00";
            goto Exit;
        }
        cout<<1;

        if(s1[2]=='A' and s2[2]=='B') same4=1;
        if(s1[2]=='B' and s2[2]=='A') same4=1;
        if(s1[2]=='B' and s2[2]=='C') same4=1;
        if(s1[2]=='C' and s2[2]=='B') same4=1;

        if(same4==0){
            cout<<0;
            goto Exit;
        }
        cout<<1;
    }else{
        cout<<"0000";
    }
    
    Exit: fclose(stdin);
    fclose(stdout);
    return 0;
}
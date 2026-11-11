#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int ans=0;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans=1000;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans=1100;
            if(abs(s1[2]-s2[2])==1){
                ans=1111;
            }
            else{
                ans=1110;
            }
        }

    }


    if(ans==0){
        cout<<"0000";
    }
    else{cout<<ans;}
    return 0;
}

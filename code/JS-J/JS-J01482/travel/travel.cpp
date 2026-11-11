#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag=true;
    for (int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            flag=false;
        }
    }
    if(!flag){
        cout<<"0000";
    } else {
        for(int i=0;i<2;i++){
            if(s1[i]!=s2[i]){
                flag=false;
            }
        }
        if(!flag){
            cout<<"1000";
        } else {
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F'))){
                cout<<"1100";
            } else {
                if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
                    cout<<"1110";
                } else {
                    cout<<"1111";
                }
            }
        }
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
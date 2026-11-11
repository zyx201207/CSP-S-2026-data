
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else{
        cout<<1;
        int xNum=0,rNum=0;
        for(int i=0;i<s1.size()-1;i++){
            xNum=xNum*10+s1[i]-'0';
        }
        for(int i=0;i<s2.size()-1;i++){
            rNum=rNum*10+s2[i]-'0';
        }
        if(xNum!=rNum){
            cout<<"000";
        }
        else{
            cout<<1;
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')==true){
                cout<<1;
                //cout<<"s1[2] -> "<<s1[2]<<" s2[2] -> "<<s2[2]<<endl;
                if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C')){
                    cout<<0;
                }
                else cout<<1;
            }
            else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')==true){
                cout<<1<<1;
            }
            else cout<<0<<0;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int sum=0;
char t[20];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
        string s;
        cin>>s;
        int j;
        for(j=sum;j<s.size()+sum;j++){
            t[j]=s[j-sum];
        }
        sum+=s.size();
    }
    if(t[0]==t[5]&&t[1]==t[6]){
        cout<<"1";
        if(t[2]==t[7]&&t[3]==t[8]){
            cout<<"1";
            if((t[4]=='D'&&t[9]=='F')||(t[4]=='F'&&t[9]=='D')||(t[4]=='A'&&t[9]=='B')||(t[4]=='B'&&t[9]=='A')||(t[4]=='A'&&t[9]=='C')||(t[4]=='C'&&t[9]=='A')||(t[4]=='B'&&t[9]=='C')||(t[4]=='C'&&t[9]=='B')){
                cout<<"1";
                if((t[4]=='D'&&t[9]=='F')||(t[4]=='F'&&t[9]=='D')||(t[4]=='A'&&t[9]=='B')||(t[4]=='B'&&t[9]=='A')||(t[4]=='B'&&t[9]=='C')||(t[4]=='C'&&t[9]=='B')){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

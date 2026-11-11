#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long n1,n2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        for(int i=0;i<=1;i++){
            n1=n1*10+s1[i]-'0';
        }
        for(int i=0;i<=1;i++){
            n2=n2*10+s2[i]-'0';
        }
        if(n1==n2){
            cout<<"1";
            if((s1[2]=='A' or s1[2]=='B' or s1[2]=='C') and (s2[2]=='A' or s2[2]=='B' or s2[2]=='C')){
                cout<<"1";
                if(abs(s2[2]-s1[2])==1){
                        cout<<"1";
                }else{
                    cout<<"0";
                }
            }else if((s1[2]=='D' or s1[2]=='F') and (s2[2]=='D' or s2[2]=='F')){
                cout<<"1";
                if(abs(s2[2]-s1[2])==1){
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
}

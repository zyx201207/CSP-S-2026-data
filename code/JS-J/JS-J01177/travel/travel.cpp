#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2&&c1!=1&&c1!=16){
        cout<<"0000";
    }else{
        cout<<"1";
        int a=10*(s1[0]-'0')+s1[1]-'0';
        int b=10*(s2[0]-'0')+s2[1]-'0';
        if(a!=b){
            cout<< "000";
        }else{
            cout<<"1";
            if(s1[2]=='C'&&s2[2]=='D'){
                cout<<"00";
            }else if(s2[2]=='C'&&s1[2]=='D'){
                cout<<"00";
            }else{
                cout<<"1";
                if(abs(s1[2]-s2[2])==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }
        }
    }
    return 0;
}

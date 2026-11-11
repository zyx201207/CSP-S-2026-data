#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    string c1,str1,c2,str2;
    cin>>c1>>str1>>c2>>str2;

    int x1,x2;
    x1=(str1[0]-'0')*10+str1[1]-'0';
    x2=(str2[0]-'0')*10+str2[1]-'0';
    if(c1==c2){
        cout<<"1";
        if(x1==x2){
            cout<<"1";
            if((str1[2]<='C' && str2[2]<='C') || (str1[2]>='D' && str2[2]>='D')){
                cout<<"1";
                if(abs(str1[2]-str2[2])==1) cout<<"1";
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0] || c1[1]!=c2[1]){
        cout<<"0000";
    }else{
        cout<<"1";
        if(s1[0]!=s2[0] || s1[1]!=s2[1]){
            cout<<"000";
        }else{
            cout<<"1";
            int a=s1[2]-'A',b=s2[2]-'A';
            int c;
            if(a<b){
                c=a;
                a=b;
                b=c;
            }
            if(a+b>3 && a>=3){
                cout<<"00";
            }else{
                cout<<"1";
                if(a==2 && b==0){
                    cout<<"0";
                }else{
                    cout<<"1";
                }
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    while(1>0){
        cout<<1;
        if(s1.size()-1==s2.size()-2){
            cout<<1;
            if(s1[2]<='2'&&s2[2]<='2' || s1[2]>='2'&&s2[2]>='2'){
                cout<<1;
                if(s1[2]<='2'&&s2[2]<='2'){
                    cout<<1;
                }else if(s1[2]>='2'&&s2[2]<='3'||s1[2]>='3'&&s2[2]<='2'){
                    cout<<1;
                }else if(s1[2]>='3'&&s2[2]<='4'||s1[2]>='4'&&s2[2]<='3'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<00;
            }
        }else{
            cout<<000;
        }
    }
    cout<<0000;

    return 0;
}

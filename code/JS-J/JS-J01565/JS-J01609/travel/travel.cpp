#include<bits/stdc++.h>
using namespace std;
int c1,c2,h1,h2;
char s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>h1>>s1>>c2>>h2>>s2;
    if(c1==c2){
        cout<<'1';
        if(h1==h2){
            cout<<'1';
            if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')||(s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='A'&&s2=='C')||(s1=='C'&&s2=='A')||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')){
                cout<<'1';
                if((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D')||(s1=='A'&&s2=='B')||(s1=='B'&&s2=='A')||(s1=='B'&&s2=='C')||(s1=='C'&&s2=='B')){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
}

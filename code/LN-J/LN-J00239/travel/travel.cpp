#include<bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2;
char c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s1>>b>>s2;
    c1=s1[2];
    c2=s2[2];
    if(a==b){
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if(c1=='A' || c1=='B' || c1=='C' && c2=='A' || c2=='B' || c2=='C'){
                cout<<1;
                if(c1+1==c2 || c2+1==c1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if(c1=='D' || c1=='F' && c2=='D' || c2=='F'){
                cout<<1<<1;
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }

    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}

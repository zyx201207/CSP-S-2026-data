#include<bits/stdc++.h>
using namespace std;
int a,b;
string sa,sb;
bool slove(char x,char y){
    if(x=='A'||x=='B'||x=='C'){
        if(y=='A'||y=='B'||y=='C') return true;
        else return false;
    }
    if(x=='D'||x=='F'){
        if(y=='D'||y=='F') return true;
        else return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sa>>b>>sb;
    if(a==b){
        cout<<1;
        if(sa[0]==sb[0]&&sa[1]==sb[1]){
                cout<<1;
            if(slove(sa[2],sb[2])){
                    cout<<1;
                 if(abs(sa[2]-sb[2])==1) {
                     cout<<1;
                     return 0;
                 }
                 cout<<0;
                 return 0;
            }
            cout<<"00";
            return 0;
        }
        cout<<"000";
        return 0;
    }
    cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

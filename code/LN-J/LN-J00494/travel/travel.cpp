#include<bits/stdc++.h>
using namespace std;
bool check(char e1,char e2){
    if(e1=='A'||e1=='B'||e1=='C'){
        return (e2=='A'||e2=='B'||e2=='C');
    }
    else{
        return (e2=='D'||e2=='F');
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char e1,e2;
    cin>>c1>>s1>>e1>>c2>>s2>>e2;
    if(c1==c2){
        cout<<"1";
        if(s1==s2){
            cout<<"1";
            if(check(e1,e2)){
                cout<<"1";
                if((abs((int)e1-(int)e2)==1)||(e1=='D'&&e2=='F'||e1=='F'&&e2=='D')){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}

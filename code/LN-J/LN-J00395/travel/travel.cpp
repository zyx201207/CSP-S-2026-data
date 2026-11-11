#include<bits/stdc++.h>
using namespace std;
int ce(char x){
    if(x=='A'||x=='B'||x=='C'){
        return 87;
    }
    else{
        return 78;
    }
}
int lin(char x,char y){
    if(abs(int(int(x)-int(y)))==1||(x=='D'&&y=='F')||(x=='F'&&y=='D')){
        return 91;
    }
    else{
        return 99;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2||c1=="01"||c2=="01"||c1=="16"||c2=="16"){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        string c1pai="";
        string c2pai="";
        c1pai+=s1[0];
        c1pai+=s1[1];
        c2pai+=s2[0];
        c2pai+=s2[1];
        if(c1pai!=c2pai){
            cout<<"000";
            return 0;
        }
        else{
            cout<<1;
            char cc1=s1[2];
            char cc2=s2[2];
            if(ce(cc1)!=ce(cc2)){
                cout<<"00";
            }
            else{
                cout<<1;
                if(lin(cc1,cc2)==99){
                    cout<<0<<endl;
                }
                else{
                    cout<<1;
                }
            }
        }
    }
}

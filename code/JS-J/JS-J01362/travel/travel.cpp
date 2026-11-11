#include<bits/stdc++.h>
using namespace std;
int checke(char x,char y){
    if(x=='A'&&(y=='B'||y=='C')){
        return 1;
    }
    if(x=='B'&&(y=='A'||y=='C')){
        return 1;
    }
    if(x=='C'&&(y=='B'||y=='A')){
        return 1;
    }
    if(x=='D'&&y=='F'){
        return 1;
    }
    if(x=='F'&&y=='D'){
        return 1;
    }
    return 0;

}
int xiangling(char x,char y){
    if(x=='A'&&y=='B'){
        return 1;
    }
    if(x=='B'&&(y=='A'||y=='C')){
        return 1;
    }
    if(x=='C'&&y=='B'){
        return 1;
    }
    if(x=='D'&&y=='F'){
        return 1;
    }
    if(x=='F'&&y=='D'){
        return 1;
    }
    return 0;


}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b;
    string sa,sb;
    cin>>a>>sa>>b>>sb;
    char x=sa[2],y=sb[2];
    //cout<<x<<" "<<y<<endl;
    //return 0;
    if(a==b){
        cout<<"1";
        if(sa[0]==sb[0]&&sa[1]==sb[1]){
            cout<<"1";
            if(checke(sa[2],sb[2])){
                cout<<"1";
                if(xiangling(sa[2],sb[2])){
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

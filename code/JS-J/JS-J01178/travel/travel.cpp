#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b[1]==d[1]&&b[0]==d[0]){
            cout<<1;
            if(b[2]=='D'&&d[2]=='F'||d[2]=='F'&&b[2]=='D') cout<<11;
            else if((int)(b[2])-1==(int)(d[2])||(int)(b[2])+1==(int)(d[2])){
                cout<<11;
            }
            else if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
                cout<<"10";
            }
            else{
                cout<<"00";
            }
        }
        else cout<<"000";
        }
    else cout<<"0000";
}


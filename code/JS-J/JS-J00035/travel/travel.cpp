#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
char x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]*10+s1[1];
    b=s2[0]*10+s2[1];
    x=s1[2];
    y=s2[2];
    if(c1==c2){
        cout<<1;
        if(a==b){
            cout<<1;
            if((x>'C'&&y>'C')||(x<'D'&&y<'D')){
                cout<<1;
                if(x+1==y||y+1==x){
                    cout<<1;
                }else{
            cout<<"0";
        }
            }else{
            cout<<"00";
        }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

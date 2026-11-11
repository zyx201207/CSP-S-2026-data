#include<bits/stdc++.h>
using namespace std;
char a,b;
int x1,x2,y,y2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %d%c %d %d%c",&x1,&y,&a,&x2,&y2,&b);
    if(x1==x2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(x1==x2&&y==y2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(x1==x2&&y==y2&&(a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='F'&&b>='D'&&b<='F')){
        cout<<1;
        if(abs(a-b)==1){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<"00";
    }
    return 0;
}

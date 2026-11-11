#include <bits/stdc++.h>
using namespace std;
string sx,ax,sy,ay;
bool judge(char x,char y){
    if((x>='D'&&y>='D')||(x<'D'&&y<'D')){
        return true;
    }else{
        return false;
    }
}
bool neigh(char x,char y){
    if(abs(x-y)==1){
        return true;
    }else if(x>='D'&&y>='D'){
        return true;
    }else{
        return false;
    }
}
void get(string x,string a,string y,string b){
    if(x==y){
        cout<<"1";
    }else{
        cout<<"0000";
        return ;
    }
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<"1";
    }else{
        cout<<"000";
        return ;
    }
    if(judge(a[2],b[2])){
        cout<<"1";
    }else{
        cout<<"00";
        return ;
    }
    if(neigh(a[2],b[2])){
        cout<<"1";
    }else{
        cout<<"0";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sx>>ax>>sy>>ay;
    get(sx,ax,sy,ay);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e="",f="",g="",h="";
    cin>>a>>b>>c>>d;
    bool n=true;
    if(a==c){
        cout <<1;
    }else{
        cout<<0;
        n=false;
    }
    for(int i=0;i<b.size();i++){
        if(b[i]>='0'&&b[i]<='9'){
            e+=b[i];
        }else{
            g+=b[i];
        }
    }
    for(int i=0;i<d.size();i++){
        if(d[i]>='0'&&d[i]<='9'){
            f+=d[i];
        }else{
            h+=d[i];
        }
    }
    if(n&&(e==f)){
        cout <<1;
    }else{
        cout <<0;
        n=false;
    }
    if(n&&(g<="C"&&h<="C")){
        cout<<1;
    }else if(n&&(g<="E"&&h<="E"&&g>="D"&&h>="D")){
        cout <<1;
    }else{
        cout <<0;
        n=false;
    }
    if(n&&(g=="A"&&h=="B")){
        cout <<1;
    }else if(n&&(h=="B"&&g=="C")){
        cout <<1;
    }else if(n&&(h=="D"&&g=="E")){
        cout<<1;
    }else if(n&&(g=="B"&&h=="C")){
        cout<<1;
    }else if(n&&(g=="D"&&h=="E")){
        cout <<1;
    }else if(n&&(h=="A"&&g=="B")){
        cout<<1;
    }else{
        cout <<0;
    }
    return 0;
}

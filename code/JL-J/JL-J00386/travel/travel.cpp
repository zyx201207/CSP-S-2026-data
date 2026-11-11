#include<bits/stdc++.h>
using namespace std;
int w,x,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0;
    }
    for(int i=0;i<b.size();i++){
        for(int j=0;j<d.size();j++){
            if(a==c&&b[0]==d[0]&&b[1]==d[1]){
                w=1;
            }
            else{
                w=0;
            }
            if(a==c&&b[0]==d[0]&&b[1]==d[1]&&b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
                x=1;
            }
            else{
                x=0;
            }
            if(a==c&&b[0]==d[0]&&b[1]==d[1]&&b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'&&d[2]+1==b[2]||d[2]-1==b[2]||b[2]+1==d[2]||b[2]-1==d[2]){
                if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
                    if(d[2]+2==b[2]||d[2]-2==b[2]||b[2]+2==d[2]||b[2]-2==d[2]){
                        y=1;
                    }
                }
            }
            else{
                y=0;
            }
        }
    }
    if(w==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(x==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(y==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char n[1000001];
bool check(int i,int h){
    char x[h+3];
    for(int j=0;j<h;j++){
        x[j]=n[j];
    }
    for(int j=0;j<i;j++){
        x[h-j-1]=x[j];
    }
        bool f=true;
    for(int j=0;j<h/2;j++){
        if(x[j]!=x[h-j-1]){
            f=false;
            break;
        }
    }
    return f;
}
int main(){
    freopen("string.in","w",stdin);
    freopen("string.out","r",stdout);
    int a,m,h=0;
    char c;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            n[h]=c;
            h++;
        }
    }
    bool f=true;
    for(int i=0;i<h/2;i++){
        if(n[i]!=n[h-i-1]){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"0";
    }else{
        for(int i=h/2;i>0;i--){
            if(!check(i,h)){
                i++;
                cout<<i;
                break;
            }
        }
    }
    return 0;
}

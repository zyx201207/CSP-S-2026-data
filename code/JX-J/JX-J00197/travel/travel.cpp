#include<bits/stdc++.h>
using namespace std;

int a,b,d=2;
char x[15],y[15];

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

cin>>a>>x>>b>>y;
int s=x[2];
int f=y[2];

if(a==b){
    cout<<"1";
}
else{
    cout<<"0";
}
if(x[0]==y[0]&&x[1]==y[1]){
    cout<<"1";
}
else{
    cout<<"0";

}
if(s<=67&&f<=67||s>=68&&f>=68){
    cout<<"1";
}
else{
    cout<<"0";
}

if(x[0]==y[0]&&x[1]==y[1]&&s<=67&&f<=67||s>=68&&f>=68){
    if(s+1==f||s-1==f){
        cout<<"1";
    }
}
else{
    d=d-1;
}
if(s==f){
    if(x[0]-1==y[0]||x[1]+1==y[1]){
        cout<<"1";
    }
}
else{
    d=d-1;
}

if(d==0){
    cout<<"0";
}
return 0;
}

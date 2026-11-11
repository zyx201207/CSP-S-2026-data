#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string n,m;
cin>>n;
cin>>m;
if(c1==01||c1==16||c2==02||c2==16){
    cout<<0;
}
else{
    cout<<1;
}

if(c1==c2){
    cout<<1;
}
else{
    cout<<0;
}
if(s1==s2+1||s1==s2-1){
    cout<<1;
}
else{
    cout<<0;
}
if(s1=='D'||s1=='C'||s2=='D'||s1=='c'){
    if(s1=='D'&&s2='C'){
        cout<<0;
    else if(s1=='C'&&s2=='D'){
        cout<<0;
    }
    else if(s2=='C'&&s1=='D'){
        cout<<0;
    }
    else if(s2=='D'&&s2=='C'){
        cout<<0;
    }
    else{
        cout<<1;
    }
    }
}
else{
    cout<<0;
}

return 0;


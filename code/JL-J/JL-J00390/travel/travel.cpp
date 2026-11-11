#include<bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
freopen("travel","r",stdin);
freopen("travel","w",stdout);

cin>>n>>a>>m>>b;
if(n[0]!=m[0]||n[1]!=m[1]){
    cout<<"0000";
    return 1;
    }
    else{
    cout<<1;
    }
 if(a[0]!=b[0]||a[1]!=b[1]){
    cout<<0<<0<<0;
    return 1;
}
else{
    cout<<1;

}

if(a[2]=='A'&&a[2]=='B'&&a[2]=='C'||b[2]!='D'&&b[2]!='E'){
cout<<1;
}
else{
       cout<<0;
}
if(a[2]=='A'||b[2]=='B'&&a[2]=='B'||b[2]=='A'&&a[2]=='B'||b[2]=='C'&&b[2]=='B'||a[2]=='C'&&a[2]=='E'||b[2]=='D'&&a[2]=='D'||b[2]=='E'){
    cout<<1;
}
else{
    cout<<0;
}
return 0;
}

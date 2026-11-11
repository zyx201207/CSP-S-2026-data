#include<bits/stdc++.h>
using namespace std;
string s,s1;
int c,c1,n,n1;

int nex=0;
char up[10]={'F','D'},down[10]={'A','B','C'};
bool sc,scb;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c>>s>>c1>>s1;
if(c==c1){
cout<<1;
}
else{
cout<<"0000";
return 0;
}
n=int(s[1]);
n1=int(s1[1]);
if(n==n1){
cout<<1;
sc=1;
}
else{
cout<<"000";
return 0;
}
for(int i=0;i<=1;i++){
for(int j=0;j<=1;j++){
if(s[2]==up[i]&&s1[2]==up[j]){
cout<<11;
return 0;
}
}
}
char a=char(s[2]),b=char(s1[2]);
for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){

        if(a==down[i]&&b==down[j]){

            cout<<1;
            nex=abs(i-j);
        }
    }
}
if(nex==0){

    cout<<"00";
    return 0;
}

if(nex==1){
cout<<1;
}
else{
cout<<0;
}




return 0;
}

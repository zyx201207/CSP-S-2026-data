#include<bits/stdc++.h>
using namespace std;
freopen ("travel.in","r",stdin);
freopen ("travel.out","w",stdin);

int main(){
int x=0;
string a,b,c.d.s;
cin>>a>>b>>c>>d;
for(int i=0;i<a.size();i++){
    if(a[i]==c[i]){
        x+=1;
    }
}
if(x==a.size()){
    s=s+"1";
}else{
    s=s+"0";
}
x=0;
for(int i=0;i<b.size()-1;i++){
    if(b[i]==d[i]){
        x+=1;
    }
}
if(x==b.size()-1){
    s=s+"1";
}else{
    s=s+"0";
}
x=0;
s=s+"1"+"1";
cout<<s<<endl;
return 0;
}


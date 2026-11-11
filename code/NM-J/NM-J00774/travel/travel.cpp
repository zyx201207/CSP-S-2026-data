#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int r;
string a,b,c,d;
char ri='0',rg='0',rh='0',rt='0';
cin>>a>>b>>c>>d;
if(a==c){
    ri='1';
}
for(int i=0;i<2;i++){
    if(b[i]==d[i]){
       r=1;
    }
    else {
          r=0;
    break;
}
}
if(r==1){
        rg='1';
   if(b[2]-'0'<=19&&d[2]-'0'<=19){
    rh='1';
    rt='1';
    if(b[2]=='A'&&d[2]=='C'){
        rt='0';

    }
    if(b[2]=='C'&&d[2]=='A'){
        rt='0';

    }
   }
   if(b[2]-'0'>19&&d[2]-'0'>19){
    rh='1';
    rt='1';
   }
}
cout<<ri<<rg<<rh<<rt;
return 0;
}

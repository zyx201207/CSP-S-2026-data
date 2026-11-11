#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
    cout<<1<<;
}else{
    cout<<0<<0;
}
int a=0,b=0;
char c,d;
for(int i=0;i<3;i++){
    if((s1[i]>='0' && s1[i]<='9') && (s2[i]>='0' && s2[i]<='9')){
        a=s1[i];
        b=s2[i];
        if(a==b){
        cout<<1;
        }else{
            cout<<0;
        }
    }
    if((s1[i]>='A'&&s1[i]<='F')&&(s2[i]>='A'&&s2[i]<='F')){
            c=s1[i];
            d=s2[i];
        }
        if(c=='A'&&d=='B'||c=='B'&&d=='C'||c=='D'&&d=='F'){
            cout<<1;
        }else{
        cout<<0;
        }
}
return 0;
}

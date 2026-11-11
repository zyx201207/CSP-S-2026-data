#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2;
string s1[1005],s2[1005];
cin>>c1;
for(int i=1;i<=3;i++){
    cin>>s1[i];
}
cin>>c2;
for(int i=1;i<=3;i++){
    cin>>s2[i];
}
if(c1==c2){
    cout<<1;
}
else{
    cout<<0;
}
for(int i=1;i<=2;i++){
        int cnt=0;
    if(s1[i]!=s2[i]){
        cnt++;
    }
    if(cnt>=1){
        cout<<0;
        break;
    }
    if(cnt==0){
        cout<<1;
        break;
    }
}
if(s1[3]<='67'||s2<='67'&&s1[3]>='68'||s2[3]>='68'){
    cout<<1;
}
else{
    cout<<0;
}
if(s1[3]>s2[3]||s1[3]-1==s2[3]||s1[3]-1!='C'){
   cout<<1;
}
else if(s1[3]<s2[3]||s1[3]+1==s2[3]||s1[3]+1!='D'){
    cout<<1;
}
else{
    cout<<0;
}


return 0;
}

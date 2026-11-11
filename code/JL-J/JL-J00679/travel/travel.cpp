#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",stdin);
    freopen("travel.out",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
int cnt=0;
if(c1==c2){
cout<<1;
}
else{
cout<<0<<0<<0<<0<<endl;
fclose(stdin);
fclose(stdout);
return 0;
}
for(int i=0;i<2;i++){
if(s1[i]==s2[i]){
cnt++;
}
}
if(cnt==2){
cout<<1;
cnt=0;
}
else{
    cnt=0;
    cout<<0<<0<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='D'&&s2[2]<='F'){
    cout<<0;
    cnt=0;
}
else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='A'&&s2[2]<='C'){
    cout<<0;
    cnt=0;
}
else{
    cout<<1;
    cnt=1;
}
if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
    if(cnt==1){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
else{
    cout<<0<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}

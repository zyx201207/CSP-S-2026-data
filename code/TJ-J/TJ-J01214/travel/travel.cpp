#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>c2>>s1>>s2;
    for(int i=1;i<2;i++){
        if(c1[i]==s1[i]){
            cout<<1;
            cnt++;
            break;
        }else{
            cout<<0;
        }
    }
    for(int i=0;i<2;i++){
        if(c2[i]==s2[i]){
            cnt++;
        }else{
            break;
            }
    }
for(int i=0;i<3;i++){
    if((c2[i]=='A'&&s2[i]=='B')||(c2[i]=='B'&&s2[i]=='A')){
        cnt++;
        break;
    }else if((c2[i]=='B'&&s2[i]=='C')||(c2[i]=='C'&&s2[i]=='B')){
        cnt++;
        break;
    }else if((c2[i]=='F'&&s2[i]=='D')||(c2[i]=='D'&&s2[i]=='F')){
        cnt++;
        break;
    }

}
if(cnt==0){
    cout<<0<<0<<0;
}
if(cnt==1){
    cout<<0<<0<<0;
}
if(cnt==2){
    cout<<1<<0<<0;
}
if(cnt==3){
    cout<<1<<1<<0;
}
if(cnt==4){
    cout<<1<<1<<1;
}
fclose(stdin);
fclose(stdout);
return 0;
}

#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cnt=0;
    for(int i=0;i<2;i++){
        if(c1[i]==c2[i]){
            cnt++;
        }
    }
    if(cnt==2){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    cnt=0;
    string s1num="";
    string s2num="";
    for(int i=0;i<2;i++){
        s1num+=s1[i];
        s2num+=s2[i];
    }
    char s1s=s1[2];
    char s2s=s2[2];
    for(int i=0;i<2;i++){
        if(s1num[i]==s2num[i]){
            cnt++;
        }
    }if(cnt==2){
        cout<<1;
    }else{
        cout<<"000"<<endl;
        return 0;
    }
    cnt=0;

    if((s1s=='A'||s1s=='B'||s1s=='C')&&(s2s=='A'||s2s=='B'||s2s=='C')){
        cout<<1;
    }else if((s1s=='D'||s1s=='F')&&(s2s=='D'||s2s=='F')){
        cout<<1;
    }else{
        cout<<"00"<<endl;
        return 0;
    }
    if(s1s=='A'){
        if(s2s=='B'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s1s=='B'){
        if(s2s=='A'||s2s=='C'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s1s=='C'){
        if(s2s=='B'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s1s=='D'){
        if(s2s=='F'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }else if(s1s=='F'){
        if(s2s=='D'){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
    return 0;
}

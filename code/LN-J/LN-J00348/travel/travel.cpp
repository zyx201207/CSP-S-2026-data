#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int chexiang1,chexiang2;
    string seat1,seat2;
    cin>>chexiang1>>seat1>>chexiang2>>seat2;
    string ans="";
    if(chexiang1!=chexiang2){
        cout<<"0000"<<endl;
        return 0;
    }
    int x=(seat1[0]-'0')*10+seat1[1]-'0',y=(seat2[0]-'0')*10+seat2[1]-'0';
    if(x!=y){
        cout<<"1000"<<endl;
        return 0;
    }
    char s1=seat1[2],s2=seat2[2];
    if(s1>='A'&&s1<='C') x=1;
    if(s1>='D'&&s1<='F') x=2;
    if(s2>='A'&&s2<='C') y=1;
    if(s2>='D'&&s2<='F') y=2;
    if(x!=y){
        cout<<"1100"<<endl;
        return 0;
    }
    if(s1+1==s2||s2+1==s1) cout<<"1111"<<endl;
    else cout<<"1110"<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

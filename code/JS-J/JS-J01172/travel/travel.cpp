#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool f1,f2,f3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w", stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1[0]==s3[0]&&s1[1]==s3[1]){
        cout<<1;
        f1=1;
    }else cout<<0;
    if(s2[0]==s4[0]&&s2[1]==s4[1]&&f1){
        cout<<1;
        f2=1;
    }else cout<<0;
    int t1=0,t2=0;
    if(s2[2]<='C') t1++;
    else t2++;
    if(s4[2]<='C') t1++;
    else t2++;
    if((t1==2||t2==2)&&f2){
        cout<<1;
        f3=1;
    }else cout<<0;
    if(abs(s2[2]-s4[2])==1&&f3){
        cout<<1;
    }else cout<<0;

    return 0;
}

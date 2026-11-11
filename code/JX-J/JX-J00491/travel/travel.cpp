#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,z1,z2;
long long q=0,q2=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="01"&&c2!="01"&&c1!="16"&&c2!="16"){
        cout<<1;
    }
    else{
        q=1;
        cout<<0;
    }
    for(int i=0;i<2;i++){
        z1+=s1[i];
        z2+=s2[i];
    }
    //cout<<z1<<' '<<z2;
    if(z1==z2&&q==0){
        cout<<1;
    }
    else{
        q=1;
        cout<<0;
    }
    if('C'>=s1[2]&&'C'>=s2[2]&&q==0){
        q2=1;
        cout<<1;
    }
    else if('F'>=s1[2]>='D'&&'F'>=s2[2]>='D'&&q==0){
        q2=1;
        cout<<1;
    }
    else{
        cout<<0;
    }
    if('C'>=s1[2]&&'C'>=s2[2]&&q2==1){
        int a=s1[2]-'A';
        int b=s2[2]-'A';
        if(a+1==b||a-1==b) cout<<1;
        else cout<<0;
    }
    else{
        int a=s1[2]-'A';
        int b=s2[2]-'A';
        if(a+2==b||a-2==b&&q2==1) cout<<1;
        else cout<<0;
    }
return 0;
}


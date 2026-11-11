#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q1=0,q2=0,q3=0,q4=0;
    string n1,n2,s1,s2;
    cin>>n1>>s1>>n2>>s2;
    if(n1!=n2){
        cout<<q1<<q2<<q3<<q4;
        return 0;
    }
    else{
        q1=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        q2=1;
    }
    else{
        cout<<1000;
        return 0;
    }
    int s3=s1[2],s4=s2[2];
    if(((s3=='A'||s3=='B'||s3=='C')&&(s4=='A'||s4=='B'||s4=='C'))||((s3=='D'||s3=='F')&&(s4=='D'||s4=='F'))){
        q3=1;
    }
    else{
        cout<<1100;
        return 0;
    }
    if((s3=='B'&&(s4=='A'||s4=='C'))||(s4=='B'&&(s3=='A'||s3=='C'))||(s3=='D'&&s4=='F')||(s4=='D'&&s3=='F')){
        cout<<1111;
    }
    else{
        cout<<1110;
    }
    return 0;
}

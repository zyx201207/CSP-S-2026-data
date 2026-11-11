#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2,cnt=0,q1,q2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if((c1!='01'||c1!='16')&&(c2!='01'||c2!='16')&&(c1==c2)){
        cout << 1;
        cnt=1;
    }
    else{
        cout << 0;
    }
    if(((s1[0]==s2[0])&&(s1[1]==s2[1]))&&cnt==1){
        cout << 1;
        cnt=2;
    }
    else{
        cout << 0;
    }
    q1=(s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C');
    q2=(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F');
    if((q1||q2)&&cnt==2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    if((((abs(s1[2]-s2[2])==1)&&q1)||((abs(s1[2]-s2[2])==2)&&q2))&&cnt==2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool a1=false,w1=false,d1=false,f1=false;
string s1,s2,s3,s4;
int main()
{
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3&&s1!="01"&&s3!="16")
        a1=true;
    if((s2[0]+s2[1])==(s4[0]+s4[1])&&a1==true)
        w1=true;
    if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='A'&&s4[2]=='C')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='E')||(s4[2]=='A'&&s2[2]=='B')||(s4[2]=='A'&&s2[2]=='C')||(s4[2]=='B'&&s2[2]=='C')||(s4[2]=='D'&&s2[2]=='E'))
        if(a1==true&&w1==true)
        d1=true;
    if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='E')||(s4[2]=='A'&&s2[2]=='B')||(s4[2]=='B'&&s2[2]=='C')||(s4[2]=='D'&&s2[2]=='E'))
        if(a1==true&&w1==true&&d1==true)
        f1=true;
        cout<<a1<<w1<<d1<<f1;
    return 0;
}

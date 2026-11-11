#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    string c1,s1,c2,s2,jg;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2) jg+="1";
    else jg+="0";

    if(jg[0]=="1"){
        if(s1[1]==s2[1]) jg+="1";
        else jg+="0";
    }

    if(jg[1]=="1"){
        if(((s1[2]=="A"||s1[2]=="B"||s1[2]=="C") && (s2[2]=="A"||s2[2]=="B"||s2[2]=="C")) || ((s1[2]=="D"||s1[2]=="F") && (s1[2]=="D"||s1[2]=="F"))) jg+="1";
        else jg+="0";
    }

    if(jg[2]=="1"){
        if(s1[2]+s2[2]=="AB" || s1[2]+s2[2]=="BA" || s1[2]+a2[2]=="BC" || s1[2]+s2[2]=="CB" || s1[2]+s2[2]=="DF" || s1[2]+s2[2]=="FD") jg+="1";
        else jg+="0";
    }


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int s[500];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    s['A']=s['B']=s['C']=1;
    s['D']=s['F']=2;
    if(s1==s3) cout<<1;
    else{
        cout<<"0000\n";
        return 0;
    }
    int a=(s2[0]-'0')*10+s2[1];
    int b=(s4[0]-'0')*10+s4[1];
    if(a==b) cout<<1;
    else{
        cout<<"000\n";
        return 0;
    }
    if(s[s2[2]]==s[s4[2]]) cout<<1;
    else{
        cout<<"00\n";
        return 0;
    }
    int t1=s2[2],t2=s4[2];
    if(s[s2[2]]==1&&abs(t1-t2)==1) cout<<1;
    else if(s[s2[2]]==2) cout<<1;
    else cout<<0;
    cout<<"\n";
    return 0;
}
//g++ travel.cpp -o travel; ./travel; diff travel.out travel1.ans
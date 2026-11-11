#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int p1,p2;
map<char,int>c;
bool check(char a,char b){
    if(a==b+1||a==b-1)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    c['A']=1;
    c['B']=1;
    c['C']=1;
    c['D']=2;
    c['E']=2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<s1.size();i++){
        if(isdigit(s1[i]))p1=p1*10+s1[i]-'0';
    }
    for(int i=0;i<s2.size();i++){
        if(isdigit(s2[i]))p2=p2*10+s2[i]-'0';
    }
    bool f=1;
    if(c1!=c2){
        f=0;
        cout<<0;
    }
    else cout<<1;
    if(f==0)cout<<0;
    else if(p1==p2){
        cout<<1;
    }
    else{
        f=0;
        cout<<0;
    }
    if(f==0)cout<<0;
    else if(c[s1[s1.size()-1]]==c[s2[s2.size()-1]]){
        cout<<1;
    }
    else {
        f=0;
        cout<<0;
    }
    if(f==0)cout<<0;
    else if(check(s1[s1.size()-1],s2[s2.size()-1])){
        cout<<1;
    }
    else cout<<0;
    return 0;
}

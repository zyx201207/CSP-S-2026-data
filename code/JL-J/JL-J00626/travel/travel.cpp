#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
string s1,s2;
char s3,s4;
int c1,c2;
int c3,c4;
int c5,c6;
int ans[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) ans[0]=1;
    else ans[0]=0;
    c3=s1[0]-'0'+s1[1]-'0';
    c4=s2[0]-'0'+s2[1]-'0';
    if(c3==c4 && c1==c2) ans[1]=1;
    else ans[1]=0;
    s3=s1[s1.size()-1];
    s4=s2[s2.size()-1];
    c5=s3-'A';
    c6=s4-'A';
    if(c3==c4 && c1==c2){
        if(c5>=0 && c5<=2){
            if(c6>=0 && c6<=2) ans[2]=1;
            else ans[2]=0;
        }
        else if(c5>=3 && c5<=4){
            if(c6>=3 && c6<=4) ans[2]=1;
            else ans[2]=0;
        }
    }
    if(ans[2]==1){
        if(c5-c6==1 || c6-c5==1) ans[3]=1;
        else ans[3]=0;
    }
    for(int i=0;i<4;i++) cout<<ans[i];
    return 0;
}

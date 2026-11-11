#include<iostream>
#include<cstring>
using namespace std;
int abs(int a){
    if(a<0){return a*-1;}
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,ans="0000";
    cin>>c1>>s1>>c2>>s2;
    int si1=0,si2=0;
    if(c1==c2){
        ans[0]='1';
        for(int i=0;i<s1.length();i++){
            if(isdigit(s1[i])){
                si1*=10;
                si1+=(s1[i]-'0');
            }if(isdigit(s2[i])){
                si2*=10;
                si2+=(s2[i]-'0');
            }
        }
        if(si1==si2){
                ans[1]='1';
                if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                    ans[2]='1';
                    ans[3]='1';
                }if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
                    ans[2]='1';
                    if(abs(s1[2]-s2[2])==1){
                        ans[3]='1';
                    }
                }
            }
    }
    cout<<ans;
    return 0;
}

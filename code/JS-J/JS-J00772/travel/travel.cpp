#include <bits/stdc++.h>
using namespace std;
int a,b,x,y;
char c,d;
string s,t,ans;
bool check1(char c,char d){
    if(c=='A' or c=='B' or c=='C'){
        if(d=='A' or d=='B' or d=='C')
            return 1;
        else
            return 0;
    }
    else{
        if(d=='D' or d=='E')
            return 1;
        return 0;
    }
}
bool check2(char c,char d){
    if((c=='A' and d=='C') or (c=='C' and d=='A'))
        return 0;
    return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s;
    cin>>b>>t;
    x=(s[0]-'0')*10+(s[1]-'0');
    y=(t[0]-'0')*10+(t[1]-'0');
    c=s[2],d=t[2];
    if(a==b){
        ans+='1';
        if(x==y){
            ans+='1';
            if(check1(c,d)){
                ans+='1';
                if(check2(c,d))
                    ans+='1';
                else
                    ans+='0';
            }
            else
                ans+='0';
        }
        else
            ans+='0';
    }
    else
        ans+='0';
    while(ans.size()<4){
        ans+='0';
    }
    cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c,s,cc,ss;
ll pos=0;
bool f=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c.size()!=cc.size()){
        f=1;
    }else{
        for(int i=0;i<c.size();i++){
            if(c[i]!=cc[i]){
                f=1;
                break;
            }
        }
    }
    if(f==0){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]&&f==0){
        cout<<1;
    }else{
        cout<<0;
    }
    if(f==0&&(s[0]==ss[0]&&s[1]==ss[1])&&((((ll)s[2])>=(ll)'D'&&((ll)ss[2])>=(ll)'D')||((ll)s[2])<=(ll)'C'&&((ll)ss[2])<=(ll)'C')){
        cout<<1;
    }else{
        cout<<0;
    }
    if(s[2]=='D'||s[2]=='C'){
        pos++;
    }
    if(ss[2]=='D'||ss[2]=='C'){
        pos++;
    }
    if(f==0&&(s[0]==ss[0]&&s[1]==ss[1])&&abs((ll)(s[2])-(ll)(ss[2]))==1&&pos<=1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}

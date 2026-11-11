#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1,s1,c2,s2;
int s[3];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    s[1]=s1[2]-'A'+(s1[2]=='F' ? 0 : 1);
    s[2]=s2[2]-'A'+(s2[2]=='F' ? 0 : 1);
    if((s[1]<=3&&s[2]<=3)||(s[1]>=4&&s[2]>=4)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(s[1]+1==s[2]||s[2]+1==s[1]){
        cout<<1;
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}

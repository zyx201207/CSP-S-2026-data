#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
string s[5];
ll c[5];
char z[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=1;i<=4;i++){
        cin>>s[i];
    }
    for(int i=1;i<=4;i++){
        for(int j=0;j<s[i].length();j++){
            if(s[i][j]>='0'&&s[i][j]<='9')c[i]=c[i]*10+(s[i][j]-'0');
            else z[i]=s[i][j];
        }
    }
    if(c[1]==c[3]){
        cout<<1;
        if(c[2]==c[4]){
            cout<<1;
            if(((z[2]=='A'&&z[4]=='B')||(z[2]=='D'&&z[4]=='E')||(z[2]=='C'&&(z[4]=='A'||z[4]=='B')))||((z[4]=='A'&&z[2]=='B')||(z[4]=='D'&&z[2]=='E')||(z[4]=='C'&&(z[2]=='A'||z[2]=='B')))){
                cout<<1;
                if(((z[2]=='A'&&z[4]=='B')||(z[2]=='C'&&z[4]=='B')||(z[2]=='D'&&z[4]=='E'))||((z[4]=='A'&&z[2]=='B')||(z[4]=='C'&&z[2]=='B')||(z[4]=='D'&&z[2]=='E'))){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

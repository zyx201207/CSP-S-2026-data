#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,e,f;
    char s,c;
    string q,p;
    cin>>a>>q>>b>>p;
    e=int(q[0]-'0')*10+int(q[1]-'0');
    f=int(p[0]-'0')*10+int(p[1]-'0');
    s=q[2];
    c=p[2];
    if(a!=b){
        cout<<"0000";
    }
    else{
        if(e==f){
            if(((s=='A' || s=='B' || s=='C') && (c=='A' || c=='B' || c=='C')) || ((s=='D' || s=='E')&&(c=='D' || c=='E'))){
                if((s=='A' && c=='B')||(s=='B'&&c=='A')||(s=='B'&&c=='C')||(s=='C'&&c=='B')||(s=='D'&&c=='E')||(s=='E'&&c=='D')){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
        }
    }
    return 0;
}

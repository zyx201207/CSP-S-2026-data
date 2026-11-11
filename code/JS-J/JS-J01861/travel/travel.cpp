#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
map<char,int>p;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    p['A']=1;
    p['B']=1;
    p['C']=1;
    p['D']=2;
    p['F']=2;

    cin>>a>>b>>c>>d;

    if(a==c){
        cout<<"1";
        if(b[0]==d[0]&&b[1]==d[1]){
            cout<<"1";
            if(p[b[2]]==p[d[2]]){
                cout<<"1";
                if(p[b[2]]==p[d[2]]){
                    if(b[2]+1==d[2]||b[2]-1==d[2])cout<<"1";
                    else cout<<"0";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}

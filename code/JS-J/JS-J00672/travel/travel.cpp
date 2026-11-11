#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string s="";
    if(a!=c){
        s="0000";
        cout<<s;
        return 0;
    }
    if(b[0]!=d[0]||b[1]!=d[1]){
        s="1000";
        cout<<s;
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]){
        s="1100";
        if((b[2] == 'A' && d[2] == 'B')||(d[2] == 'A' && b[2] == 'B'))s="1111";
        else if((b[2] == 'B' && d[2] == 'C')||(d[2] == 'B' && b[2] == 'C'))s="1111";
        else if((b[2] == 'D' && d[2] == 'E')||(d[2] == 'D' && b[2] == 'E'))s="1111";
        else if((b[2] == 'A' && d[2] == 'C')||(d[2] == 'A' && b[2] == 'C'))s="1110";
    }
    cout<<s;
    return 0;
}

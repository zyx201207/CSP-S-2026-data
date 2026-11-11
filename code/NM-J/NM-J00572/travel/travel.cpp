#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c,b,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b[1]!=d[1]||b[0]!=d[0]){
        cout<<"1000";
        return 0;
    }
    if((b[2]=='D'&&d[2]=='E')||(d[2]=='D'&&b[2]=='E')||(b[2]!='D'&&d[2]!='E'&&d[2]!='D'&&b[2]!='E')){
        if(b[2]=='D'||d[2]=='D'||d[2]=='B'||b[2]=='B'){
            cout<<"1111";
            return 0;
        }
        cout<<"1110";
        return 0;
    }
    cout<<"1100";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

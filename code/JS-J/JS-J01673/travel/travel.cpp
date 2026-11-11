#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int ax=(a[0]-'0')*10+a[1]-'0';
    int bx=(b[0]-'0')*10+b[1]-'0';
    char bc=b[2];
    int blr=(b[2]<='C');
    char dc=d[2];
    int dlr=(d[2]<='C');
    int cx=(c[0]-'0')*10+c[1]-'0';
    int dx=(d[0]-'0')*10+d[1]-'0';
    if(ax!=cx){
        cout<<"0000";
        return 0;
    }
    if(bx!=dx){
        cout<<"1000";
        return 0;
    }
    if(dlr!=blr){
        cout<<"1100";
        return 0;
    }
    if(abs(bc-dc)!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string m,n;
long long a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>m>>b>>n;
    if(a==b) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(m[0]==n[0]&&m[1]==n[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((m[2]=='A'||m[2]=='B'||m[2]=='C')&&(n[2]=='A'||n[2]=='B'||n[2]=='C')) cout<<"1";
    else if((m[2]=='D'||m[2]=='F')&&(n[2]=='D'||n[2]=='F')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if((m[2]=='A'&&n[2]=='B')||(m[2]=='C'&&n[2]=='B')||(m[2]=='B'&&n[2]=='A')||(m[2]=='B'&&n[2]=='C')||(m[2]=='F'&&n[2]=='D')||(m[2]=='D'&&n[2]=='F')) cout<<"1";
    else{
        cout<<"0";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
